#pragma once
#include "Gambler.h"

class Strategy;

class Player :
	public Gambler
{
protected:
	long long iBudget;

	Strategy * strategy;

	int SplitCards(int srchand);
	int MakeDecision(bitset<5> allowSet, int hand=0);

	void GetPays(double multiplier, int hand=0);

public:
	long long iBet;
	string ShowName(void);

	void SetBudget(long long);
	long long ShowBudget(void);

	void FixBet(long long);
	void PlaceBet(int hand=0);
	void RaiseBet(long long, int hand=0);
	void DoubleBet(int hand=0);

	void JoinTable(Table *);

	void UseStrategy(Strategy *);

	Player(void);
	Player(string);
	~Player(void);

	friend class Game;
};
