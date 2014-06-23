#pragma once
#include "Blackjack.h"
#include "BettingSystem.h"

class Hand;
class Table;

class FlowCounting :
	public BettingSystem
{
public:
	long long CalculateBet(long long iPreferredBet = 0, long long iBudget = 0,
			Table *table = 0);

	FlowCounting(void);
	virtual ~FlowCounting(void);
};
