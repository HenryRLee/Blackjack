#pragma once
#include "Blackjack.h"
#include "GameTerm.h"

class Table;
class Gambler;
class Hand;

class Statistics
{
public:
	virtual void Update(Table *) = 0;
	virtual void Update(Gambler *) = 0;
	virtual void Update(Hand *) = 0;
	virtual void Update(int action) = 0;

	Statistics(void);
	virtual ~Statistics(void);
};
