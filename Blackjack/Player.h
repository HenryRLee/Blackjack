#pragma once
#include "Gambler.h"

class Strategy;

class Player :
	public Gambler
{
protected:
	double iBudget;

	Strategy * strategy;

	int SplitCards(int srchand);
	int MakeDecision(bitset<5> actionset, int hand=0);

	void GetPays(double multiplier, int hand=0);

public:
	string ShowName(void);

	void SetBudget(double);

	void PlaceBid(double, int hand=0);
	void RaiseBid(double, int hand=0);
	void DoubleBid(int hand=0);

	void JoinTable(Table *);

	void UseStrategy(Strategy *);

	Player(void);
	Player(string);
	~Player(void);

	friend class Game;
};
