#include "Game.h"
#include "Table.h"
#include "Player.h"
#include "Dealer.h"
#include "ShuffleMachine.h"
#include "Statistics.h"

void inline Game::DealInitialCards(Dealer * dealer, 
		vector <class Player *> vPlayer)
{
	Card pop;

	pop = shuffler->PopOneCard();
	dealer->GetOneCard(pop);

	for (int i=0; i<vPlayer.size(); i++)
	{
		pop = shuffler->PopOneCard();
		vPlayer[i]->GetOneCard(pop);

		pop = shuffler->PopOneCard();
		vPlayer[i]->GetOneCard(pop);
	}
}

void inline Game::DealOneCard(Gambler * gambler, Table * table, int hand)
{
	Card pop;
	
	pop = shuffler->PopOneCard();
	gambler->GetOneCard(pop, hand);
	table->GetOneCard(pop);
}

void Game::PlayerAction(Player * player, bitset<5> allowSet, int iHand)
{
	int action;
	Hand * handCurrent = &(player->vHand[iHand]);

	if (player->vHand.size() <= iHand)
		return;

	if (handCurrent->vCard.size() >= 2)
	{
		if (handCurrent->vCard[0].GetValue() != 
			handCurrent->vCard[1].GetValue())
		{
			allowSet.set(SPLIT, 0);
		}
	}

	statistics->Update(*handCurrent);
	action = player->MakeDecision(allowSet, iHand);

	if (allowSet[action] == 0)
	{
		statistics->Update("Action not available");
		PlayerAction(player, allowSet, iHand);
	}

	switch (action)
	{
	case HIT:
		if (!bLateSurrender)
			allowSet.set(SURRENDER, 0);

		if (!bDoubleAfterHit)
			allowSet.set(DOUBLE, 0);

		allowSet.set(SPLIT, 0);

		DealOneCard(player, table, iHand);

		if (handCurrent->GetScore() > MaxScore)
			handCurrent->iStatus = BUSTED;
		else
			PlayerAction(player, allowSet, iHand);
		break;

	case STAND:
		handCurrent->iStatus = WAITING;
		break;

	case DOUBLE:
		if (!bHitAfterDouble)
		{
			allowSet.set(HIT, 0);
			allowSet.set(DOUBLE, 0);
		}
		else if (!bDoubleAfterDouble)
		{
			allowSet.set(DOUBLE, 0);
		}

		if (!bLateSurrender)
			allowSet.set(SURRENDER, 0);

		allowSet.set(SPLIT, 0);

		player->DoubleBet(iHand);
		DealOneCard(player, table, iHand);

		if (handCurrent->GetScore() > MaxScore)
		{
			handCurrent->iStatus = BUSTED;
		}
		else
		{
			if (bHitAfterDouble)
				PlayerAction(player, allowSet, iHand);
			else
				handCurrent->iStatus = DOUBLEDWAITING;
		}

		break;

	case SURRENDER:
		handCurrent->iStatus = SURRENDERED;

		break;

	case SPLIT:
		int iSplittedHand;
		iSplittedHand = player->SplitCards(iHand);

		if (!bHitAfterSplit)
		{
			allowSet.set(HIT, 0);
			allowSet.set(DOUBLE, 0);
			allowSet.set(SPLIT, 0);
		}
		else
		{
			if (!bDoubleAfterSplit)
				allowSet.set(DOUBLE, 0);

			if (!bLateSurrender)
				allowSet.set(SURRENDER, 0);

			if (!bSplitAfterSplit)
				allowSet.set(SPLIT, 0);
			else if (iSplittedHand >= iTimesSplittedAllow)
				allowSet.set(SPLIT, 0);
			else if ((!bResplitAces) && (player->vHand[iHand].vCard[0].GetValue()==11))
				allowSet.set(SPLIT, 0);
		}

		if (!bLateSurrender)
			allowSet.set(SURRENDER, 0);

		DealOneCard(player, table, iHand);
		PlayerAction(player, allowSet, iHand);

		player->PlaceBet(iSplittedHand);
		DealOneCard(player, table, iSplittedHand);
		PlayerAction(player, allowSet, iSplittedHand);

		break;

	default:
		break;
	}
}

void Game::DealerAction(Dealer * dealer)
{
	int action;

	if (dealer->vHand.size() <= 0)
		return;

	action = dealer->MakeDecision(bHitOnSoft17);

	switch (action)
	{
	case HIT:
		DealOneCard(dealer, table);

		if (dealer->vHand[0].GetScore() > MaxScore)
			dealer->vHand[0].iStatus = BUSTED;
		else
			DealerAction(dealer);

		break;

	case STAND:
		break;

	default:
		break;
	}
}

void Game::OneHandRoutine(Dealer * dealer, vector <class Player *> vPlayer,
		Table * table)
{
	Card cardPop;

	this->table = table;

	if (table == NULL)
		return;

	table->CleanTable();

	for (int i=0; i<vPlayer.size(); i++)
		vPlayer[i]->PlaceBet();

	shuffler->ShuffleCards();

	DealInitialCards(dealer, vPlayer);

	statistics->Update(table, "Dealt initial cards");
	statistics->Update(" ");

	for (int i=0; i<vPlayer.size(); i++)
	{
		bitset <5> allowSet;

		if (vPlayer[i]->vHand[0].GetScore() == MaxScore)
		{
			/* Blackjack */
			vPlayer[i]->vHand[0].iStatus = BJ;
	
			break;
		}

		allowSet.set(HIT);
		allowSet.set(STAND);

		if (bDouble)
			allowSet.set(DOUBLE);

		if (bSurrender)
		{
			allowSet.set(SURRENDER);

			if (!bSurrenderVsDealerAce)
			{
				if (dealer->vHand.size() > 0)
				{
					if (dealer->vHand[0].vCard.size() > 0)
					{
						if (dealer->vHand[0].vCard[0].GetValue() == 11)
							allowSet.set(SURRENDER, 0);
					}
				}
			}
		}

		if (bSplit)
			allowSet.set(SPLIT);

		PlayerAction(vPlayer[i], allowSet);
	}

	DealOneCard(dealer, table);

	if ((dealer->vHand[0].vCard[0].GetValue() +
				dealer->vHand[0].vCard[1].GetValue()) == MaxScore)
	{
		/* Blackjack */
		dealer->vHand[0].iStatus = BJ;
	}
	else
	{
		DealerAction(dealer);
	}

	statistics->Update(" ");
	statistics->Update(dealer, "Final hands");
	statistics->Update(" ");

	if (dealer->vHand.size() > 0)
	{
		for (int i=0; i<vPlayer.size(); i++)
		{
			statistics->Update(vPlayer[i], "Final hands");
			for (int j=0; j<vPlayer[i]->vHand.size(); j++)
			{
				if (vPlayer[i]->vHand[j].iStatus == BJ)
				{
					vPlayer[i]->GetPays(dBlackJackPays);

					statistics->Update("  PLAYER HAS A BLACKJACK");
				}
				else if (vPlayer[i]->vHand[j].iStatus == BUSTED)
				{
					vPlayer[i]->vHand[j].iStatus = LOST;

					statistics->Update("  PLAYER BUSTS");
				}
				else if (vPlayer[i]->vHand[j].iStatus == SURRENDERED)
				{
					vPlayer[i]->GetPays(0.5, j);

					statistics->Update("  PLAYER SURRENDERS");
				}
				else if (dealer->vHand[0].iStatus == BUSTED)
				{
					vPlayer[i]->vHand[j].iStatus = WON;
					vPlayer[i]->GetPays(2, j);

					statistics->Update("  DEALER BUSTS");
				}
				else if (dealer->vHand[0].iStatus == BJ)
				{
					/* 
					 * If Dealer has a Blackjack, player loses even if he has a
					 * 21. However, some rules may allow player lose original
					 * bet only when doubling and splitting.
					 */
					if (vPlayer[i]->vHand[j].iStatus == DOUBLEDWAITING)
					{
						/* Double loses original bet */
						if (bDOBO)
						{
							if (!bSOBO || (j==0))
							{
								vPlayer[i]->GetPays(0.5, j);
								vPlayer[i]->vHand[j].iStatus = LOST;
								statistics->Update("  OBO IN DOUBLE");
							}
							else
							{
								/* Splitted hand. Will be handled later. */
							}
						}
					}

					if ((bSOBO) && (j>0))
					{
						/* Splitted hand. Pay back all */
						vPlayer[i]->GetPays(1, j);
						vPlayer[i]->vHand[j].iStatus = PUSH;
						statistics->Update("  OBO IN SPLIT");
					}
					else
					{
						vPlayer[i]->vHand[j].iStatus = LOST;
						statistics->Update("  DEALER HAS A BLACKJACK");
					}
				}
				else if (vPlayer[i]->vHand[j].GetScore() > dealer->vHand[0].GetScore())
				{
					vPlayer[i]->vHand[j].iStatus = WON;
					vPlayer[i]->GetPays(2, j);

					statistics->Update("  PLAYER WINS");
				}
				else if (vPlayer[i]->vHand[j].GetScore() == dealer->vHand[0].GetScore())
				{
					vPlayer[i]->vHand[j].iStatus = PUSH;
					vPlayer[i]->GetPays(1, j);

					statistics->Update("  PUSH");
				}
				else if (vPlayer[i]->vHand[j].GetScore() < dealer->vHand[0].GetScore())
				{
					vPlayer[i]->vHand[j].iStatus = LOST;

					statistics->Update("  PLAYER LOSES");
				}
			}
		}
	}
					
	statistics->Update(" ");
	statistics->Update(table, "Game complete");

	this->table = NULL;
}

void Game::UseStatistics(Statistics * statistics)
{
	this->statistics = statistics;
}

Game::Game(void)
{
}

Game::~Game(void)
{
}
