#pragma once
#include "Gambler.h"

class Dealer :
	public Gambler
{
public:
	void JoinTable(Table *);

	Dealer(void);
	~Dealer(void);
};
