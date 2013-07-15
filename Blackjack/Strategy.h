#pragma once
#include "Blackjack.h"
#include "GameTerm.h"

using namespace GameTerm;

class Hand;
class Table;

class Strategy
{
public:
	virtual int MakeDecision(Hand handCurrent, bitset <5> allowset, Table table) = 0;

	Strategy(void);
	virtual ~Strategy(void);
};
