#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include "ShuffleMachine.h"

void inline Game::DealInitialCards(Dealer * dealer, 
		vector < class Player * > vPlayer)
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

void inline Game::DealOneCard(Gambler * gambler, int hand)
{
	Card pop;
	
	pop = shuffler->PopOneCard();
	gambler->GetOneCard(pop, hand);
}

void Game::PlayerAction(Player * player, bitset<5> allowset, int iHand)
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
			allowset.set(SPLIT, 0);
		}
	}

	action = player->MakeDecision(allowset, iHand);

	switch (action)
	{
	case HIT:
		if (!bLateSurrender)
			allowset.set(SURRENDER, 0);

		if (!bDoubleAfterHit)
			allowset.set(DOUBLE, 0);

		allowset.set(SPLIT, 0);

		DealOneCard(player, iHand);

		if (handCurrent->GetScore() > MaxScore)
			handCurrent->iStatus = BUSTED;
		else
			PlayerAction(player, allowset, iHand);
		break;

	case STAND:
		handCurrent->iStatus = WAITING;
		break;

	case DOUBLE:
		if (!bHitAfterDouble)
		{
			allowset.set(HIT, 0);
			allowset.set(DOUBLE, 0);
		}
		else if (!bDoubleAfterDouble)
		{
			allowset.set(DOUBLE, 0);
		}

		if (!bLateSurrender)
			allowset.set(SURRENDER, 0);

		allowset.set(SPLIT, 0);

		player->DoubleBid(iHand);
		DealOneCard(player, iHand);

		if (handCurrent->GetScore() > MaxScore)
			handCurrent->iStatus = BUSTED;
		else
			PlayerAction(player, allowset, iHand);

		break;

	case SURRENDER:
		handCurrent->iStatus = SURRENDERED;

		break;

	case SPLIT:
		int iSplittedHand;
		iSplittedHand = player->SplitCards(iHand);

		if (!bHitAfterSplit)
		{
			allowset.set(HIT, 0);
			allowset.set(DOUBLE, 0);
			allowset.set(SPLIT, 0);
		}
		else
		{
			if (!bDoubleAfterSplit)
				allowset.set(DOUBLE, 0);

			if (!bSplitAfterSplit)
				allowset.set(SPLIT, 0);
			else if (iSplittedHand >= iTimesSplittedAllow)
				allowset.set(SPLIT, 0);
		}

		if (!bLateSurrender)
			allowset.set(SURRENDER, 0);

		DealOneCard(player, iHand);
		PlayerAction(player, allowset, iHand);

		DealOneCard(player, iSplittedHand);
		PlayerAction(player, allowset, iSplittedHand);

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
		DealOneCard(dealer);

		if (dealer->vHand[0].iScore > MaxScore)
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

void Game::OneHandRoutine(Dealer * dealer, vector < class Player * > vPlayer,
		Table * table)
{
	Card cardPop;

	shuffler->ShuffleCards();

	DealInitialCards(dealer, vPlayer);

	for (int i=0; i<vPlayer.size(); i++)
	{
		bitset <5> allowset;

		if (vPlayer[i]->vHand[0].iScore == MaxScore)
		{
			/* Blackjack */
			vPlayer[i]->vHand[0].iStatus = BJ;
	
			break;
		}

		allowset.set(HIT);
		allowset.set(STAND);

		if (bDouble)
			allowset.set(DOUBLE);

		if (bSurrender)
			allowset.set(SURRENDER);

		if (bSplit)
			allowset.set(SPLIT);

		PlayerAction(vPlayer[i], allowset);
	}

	DealOneCard(dealer);
	DealerAction(dealer);

	if (dealer->vHand.size() > 0)
	{
		for (int i=0; i<vPlayer.size(); i++)
		{
			for (int j=0; j<vPlayer[i]->vHand.size(); j++)
			{
				if (vPlayer[i]->vHand[j].iStatus == BJ)
				{
					vPlayer[i]->GetPays(dBlackJackPays);
				}
				else if (vPlayer[i]->vHand[j].iStatus == BUSTED)
				{
					vPlayer[i]->vHand[j].iStatus = LOST;
				}
				else if (vPlayer[i]->vHand[j].iStatus == SURRENDERED)
				{
					vPlayer[i]->GetPays(0.5);
				}
				else if (dealer->vHand[0].iStatus == BUSTED)
				{
					vPlayer[i]->vHand[j].iStatus = WON;
					vPlayer[i]->GetPays(2);
				}
				else if (vPlayer[i]->vHand[j].iScore > dealer->vHand[0].iScore)
				{
					vPlayer[i]->vHand[j].iStatus = WON;
					vPlayer[i]->GetPays(2);
				}
				else if (vPlayer[i]->vHand[j].iScore == dealer->vHand[0].iScore)
				{
					vPlayer[i]->vHand[j].iStatus = PUSH;
					vPlayer[i]->GetPays(1);
				}
				else if (vPlayer[i]->vHand[j].iScore == dealer->vHand[0].iScore)
				{
					vPlayer[i]->vHand[j].iStatus = LOST;
				}
			}
		}
	}
					
}

Game::Game(void)
{
}

Game::~Game(void)
{
}
