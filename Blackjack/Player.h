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
	double iBet;
	string ShowName(void);

	void SetBudget(double);
	double ShowBudget(void);

	void FixBet(double);
	void PlaceBet(int hand=0);
	void RaiseBet(double, int hand=0);
	void DoubleBet(int hand=0);

	void JoinTable(Table *);

	void UseStrategy(Strategy *);

	Player(void);
	Player(string);
	~Player(void);

	friend class Game;
};
