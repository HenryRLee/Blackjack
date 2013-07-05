#pragma once
#include "Blackjack.h"
#include "Hand.h"
#include "Game.h"

class Table;

using namespace GameTerm;

class Gambler
{
protected:
	Table *table;

public:
	vector <Hand> vHand;

	virtual void JoinTable(Table *) = 0;
	virtual int MakeDecision(int hand=0) = 0;

	void GetOneCard(class Card, int hand=0);
	void CleanHands(void);

	Gambler(void);
	virtual ~Gambler(void);
};
