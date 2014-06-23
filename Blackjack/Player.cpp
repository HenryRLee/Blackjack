#include "Player.h"
#include "Table.h"
#include "Strategy.h"
#include "BettingSystem.h"

string Player::ShowName(void)
{
	return "[Player]" + name;
}

void Player::SetBudget(long long budget)
{
	this->iBudget = budget;
}

long long Player::ShowBudget(void)
{
	return iBudget;
}

void Player::PreferBet(long long bet)
{
	iPreferredBet = bet;
}

void Player::PlaceBet(int hand)
{
	if (bettingsystem)
		iBet = bettingsystem->CalculateBet(iPreferredBet, iBudget, table);
	else
		iBet = iPreferredBet;

	if (iBet < 0)
		iBet = 0;

	if (vHand.size() > hand)
	{
		vHand[hand].iBet = iBet;
		iBudget -= iBet;
	}
}

void Player::RaiseBet(long long bet, int hand)
{
	if (vHand.size() > hand)
	{
		vHand[hand].iBet += bet;
		iBudget -= bet;
	}
}

void Player::DoubleBet(int hand)
{
	if (vHand.size() > hand)
	{
		RaiseBet(vHand[hand].iBet, hand);
	}
}

void Player::GetPays(double multiplier, int hand)
{
	if (vHand.size() > hand)
	{
		iBudget += vHand[hand].iBet * multiplier;
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

int Player::MakeDecision(bitset<5> allowSet, int hand)
{
	if ((vHand.size() > hand) && table)
	{
		int action;

		action = strategy->MakeDecision(vHand[hand], allowSet, *table);
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

void Player::UseBettingSystem(BettingSystem * bettingsystem)
{
	this->bettingsystem = bettingsystem;
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
