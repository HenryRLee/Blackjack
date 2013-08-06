#include "Table.h"
#include "Game.h"
#include "Player.h"
#include "Dealer.h"

void Table::AddDealer(Dealer * dealer)
{
	if (this->dealer == NULL)
		this->dealer = dealer;
}

void Table::AddPlayer(Player * player)
{
	vPlayer.push_back(player);
}

void Table::DelDealer(Dealer * dealer)
{
	if (this->dealer == dealer)
		this->dealer = NULL;
}

void Table::DelPlayer(Player * player)
{
	for (int i=0; i<vPlayer.size(); i++)
	{
		if (vPlayer[i] == player)
			vPlayer.erase(vPlayer.begin() + i);
	}
}

void Table::CleanTable(void)
{
	for (int i=0; i<vPlayer.size(); i++)
	{
		vPlayer[i]->CleanHands();
	}

	dealer->CleanHands();
}

void Table::UseGameType(Game * game)
{
	this->gametype = game;
}

void Table::StartOneGame(void)
{
	if ((dealer != NULL) && (vPlayer.size()>0))
		gametype->OneHandRoutine(dealer, vPlayer, this);
}

void Table::StartMultipleGames(int num)
{
	if ((dealer != NULL) && (vPlayer.size()>0))
	{
		for (int i=0; i<num; i++)
			gametype->OneHandRoutine(dealer, vPlayer, this);
	}
}

Table::Table(void)
{
	dealer = NULL;
}

Table::~Table(void)
{
}
