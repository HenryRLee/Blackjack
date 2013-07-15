#pragma once
#include "Strategy.h"

class BasicStrategy :
	public Strategy
{
public:
	int MakeDecision(Hand handCurrent, bitset <5> allowset, Table table);

	BasicStrategy(void);
	~BasicStrategy(void);
};
