#pragma once
#include "Gambler.h"

class Strategy;
class BettingSystem;

class Player :
	public Gambler
{
protected:
	long long iBudget;

	Strategy * strategy;
	BettingSystem * bettingsystem;

	int SplitCards(int srchand);
	int MakeDecision(bitset<5> allowSet, int hand=0);

	void GetPays(double multiplier, int hand=0);

public:
	long long iBet;
	long long iPreferredBet;
	string ShowName(void);

	void SetBudget(long long);
	long long ShowBudget(void);

	void PreferBet(long long);
	void PlaceBet(int hand=0);
	void RaiseBet(long long, int hand=0);
	void DoubleBet(int hand=0);

	void JoinTable(Table *);

	void UseStrategy(Strategy *);
	void UseBettingSystem(BettingSystem *);

	Player(void);
	Player(string);
	~Player(void);

	friend class Game;
};
