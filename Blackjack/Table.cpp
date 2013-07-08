#include "Table.h"
#include "Game.h"

void Table::AddDealer(Dealer * dealer)
{
	if (this->dealer != NULL)
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

void Table::UseGameType(Game * game)
{
	this->gametype = game;
}

void Table::StartOneGame(void)
{
	gametype->OneHandRoutine(dealer, vPlayer);
}

Table::Table(void)
{
	dealer = NULL;
}

Table::~Table(void)
{
}
