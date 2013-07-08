#pragma once
#include "Gambler.h"

class Dealer :
	public Gambler
{
public:
	void JoinTable(Table *);

	int MakeDecision(bool bHitOnSoft17, int hand=0);

	Dealer(void);
	~Dealer(void);
};
