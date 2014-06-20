#pragma once
#include "Blackjack.h"
#include "BettingSystem.h"

class Hand;
class Table;

class FixedBet :
	public BettingSystem
{
public:
	long long CalculateBet(long long iPreferredBet = 0, long long iBudget = 0,
			Table *table = 0);

	FixedBet(void);
	virtual ~FixedBet(void);
};
