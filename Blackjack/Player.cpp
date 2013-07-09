#include "Player.h"
#include "Table.h"

void Player::SetBudget(double budget)
{
	this->iBudget = budget;
}

void Player::PlaceBid(double bid, int hand)
{
	if (vHand.size() > hand)
	{
		vHand[hand].iBid = bid;
		iBudget -= bid;
	}
}

void Player::RaiseBid(double bid, int hand)
{
	if (vHand.size() > hand)
	{
		vHand[hand].iBid += bid;
		iBudget -= bid;
	}
}

void Player::DoubleBid(int hand)
{
	if (vHand.size() > hand)
	{
		RaiseBid(vHand[hand].iBid);
	}
}

void Player::GetPays(double mutiplier, int hand)
{
	if (vHand.size() > hand)
	{
		iBudget += vHand[hand].iBid * mutiplier;
	}
}

int Player::SplitCards(int iSrcHand)
{
	Hand handNew;
	Card cardPop;
	int iNewHand;

	iNewHand = vHand.size();
	cardPop = vHand[iSrcHand].vCard.back();

	handNew.vCard.push_back(cardPop);
	vHand[iSrcHand].vCard.pop_back();

	vHand.push_back(handNew);

	return iNewHand;
}

void Player::JoinTable(Table * table)
{
	table->AddPlayer(this);

	this->table = table;
}

int Player::MakeDecision(bitset<5> actionset, int hand)
{
	if (vHand.size() > hand)
	{
		return STAND;
	}
	else
	{
		return -1;
	}
}

Player::Player(void)
{
	iBudget = 1000*1000;
}

Player::Player(string name)
{
	this->name = name;
	iBudget = 1000*1000;
}

Player::~Player(void)
{
}
