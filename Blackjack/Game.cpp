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

	action = player->MakeDecision(iHand);

	switch (action)
	{
	case HIT:
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
		player->DoubleBid(iHand);
		DealOneCard(player, iHand);

		if (handCurrent->GetScore() > MaxScore)
			handCurrent->iStatus = BUSTED;
		else
			PlayerAction(player, allowset, iHand);

		break;

	case SURRENDER:
		handCurrent->iStatus = LOST;
		player->GetPays(0.5);

		break;

	case SPLIT:
		int iSplittedHand;
		iSplittedHand = player->SplitCards(iHand);

		DealOneCard(player, iHand);
		PlayerAction(player, allowset, iHand);

		DealOneCard(player, iSplittedHand);
		PlayerAction(player, allowset, iSplittedHand);

		break;

	default:
		break;
	}
}

void Game::OneHandRoutine(Dealer * dealer, vector < class Player * > vPlayer)
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
			vPlayer[i]->GetPays(1.5);

			break;
		}

		PlayerAction(vPlayer[i], allowset);
	}
}

Game::Game(void)
{
}

Game::~Game(void)
{
}
