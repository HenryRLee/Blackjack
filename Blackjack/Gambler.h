#pragma once
#include "Blackjack.h"
#include "Hand.h"
#include "GameTerm.h"

class Table;

using namespace GameTerm;

class Gambler
{
protected:
	string name;

	Table *table;

	void GetOneCard(class Card, int hand=0);
	void CleanHands(void);

public:
	vector <Hand> vHand;

	virtual void JoinTable(Table *) = 0;

	Gambler(void);
	Gambler(string);
	virtual ~Gambler(void);

	friend class Game;
	friend class Table;
};
