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
	int MakeDecision(bitset<5> allowSet, int hand=0);

	void GetPays(double multiplier, int hand=0);

public:
	double iBid;
	string ShowName(void);

	void SetBudget(double);
	double ShowBudget(void);

	void FixBid(double);
	void PlaceBid(int hand=0);
	void RaiseBid(double, int hand=0);
	void DoubleBid(int hand=0);

	void JoinTable(Table *);

	void UseStrategy(Strategy *);

	Player(void);
	Player(string);
	~Player(void);

	friend class Game;
};
