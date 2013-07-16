#pragma once
#include "Blackjack.h"
#include "GameTerm.h"

class Table;
class Gambler;
class Hand;

class Statistics
{
public:
	virtual void Update(Table *, string text="") = 0;
	virtual void Update(Gambler *, string text="") = 0;
	virtual void Update(Hand, string text="") = 0;
	virtual void Update(string text="") = 0;

	Statistics(void);
	virtual ~Statistics(void);
};
