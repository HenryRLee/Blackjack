#pragma once
#include "Blackjack.h"

class Hand;
class Table;

class BettingSystem
{
public:
	virtual long long CalculateBet(long long iPreferredBet = 0,
			long long iBudget = 0, Table *table = 0) = 0;

	BettingSystem(void);
	virtual ~BettingSystem(void);
};
