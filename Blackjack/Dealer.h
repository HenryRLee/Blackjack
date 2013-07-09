#pragma once
#include "Gambler.h"

class Dealer :
	public Gambler
{
protected:
	int MakeDecision(bool bHitOnSoft17, int hand=0);

public:
	void JoinTable(Table *);

	Dealer(void);
	Dealer(string);
	~Dealer(void);

	friend class Game;
};
