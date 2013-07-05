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

void inline Game::DealOneCard(Gambler * gambler)
{
	Card pop;
	
	pop = shuffler->PopOneCard();
	gambler->GetOneCard(pop);
}

void Game::PlayerAction(Player * player, bitset<5> allowset, int hand)
{
	int action;

	action = player->MakeDecision(hand);
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
