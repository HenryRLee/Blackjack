#include "Player.h"
#include "Table.h"
#include "Strategy.h"

string Player::ShowName(void)
{
	return "[Player]" + name;
}

void Player::SetBudget(double budget)
{
	this->iBudget = budget;
}

double Player::ShowBudget(void)
{
	return iBudget;
}

void Player::FixBid(double bid)
{
	iBid = bid;
}

void Player::PlaceBid(int hand)
{
	if (vHand.size() > hand)
	{
		vHand[hand].iBid = iBid;
		iBudget -= iBid;
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
		RaiseBid(vHand[hand].iBid, hand);
	}
}

void Player::GetPays(double multiplier, int hand)
{
	if (vHand.size() > hand)
	{
		iBudget += vHand[hand].iBid * multiplier;
	}
}

int Player::SplitCards(int iSrcHand)
{
	Hand handNew;
	Card cardPop;
	int iNewHand;

	iNewHand = vHand.size();

	vHand.push_back(handNew);

	cardPop = vHand[iSrcHand].RemoveLastCard();
	GetOneCard(cardPop, iNewHand);

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
		int action;

		action = strategy->MakeDecision(vHand[hand], actionset, *table);
		return action;
	}
	else
	{
		return -1;
	}
}

void Player::UseStrategy(Strategy * strategy)
{
	this->strategy = strategy;
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
