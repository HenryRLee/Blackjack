#pragma once
#include "Gambler.h"

class Player :
	public Gambler
{
protected:
	double iBudget;

public:
	int iHandsSplitted;

	void PlaceBid(double, int hand=0);
	void RaiseBid(double, int hand=0);
	void DoubleBid(int hand=0);
	void GetPays(double multiplier, int hand=0);

	void JoinTable(Table *);
	int MakeDecision(bitset<5> actionset, int hand=0);

	Player(void);
	~Player(void);
};
