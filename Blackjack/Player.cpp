#include "Player.h"
#include "Table.h"

void Player::PlaceBid(double bid, int hand)
{
	vHand[hand].iBid = bid;
	iBudget -= bid;
}

void Player::RaiseBid(double bid, int hand)
{
	vHand[hand].iBid += bid;
	iBudget -= bid;
}

void Player::DoubleBid(int hand)
{
	RaiseBid(vHand[hand].iBid);
}

void Player::GetPays(double mutiplier, int hand)
{
	iBudget += vHand[hand].iBid * mutiplier;
}

void Player::JoinTable(Table * table)
{
	table->AddPlayer(this);

	this->table = table;
}

int Player::MakeDecision(bitset<5> actionset, int hand)
{
	return STAND;
}

Player::Player(void)
{
	iBudget = 1000*1000;
}

Player::~Player(void)
{
}
