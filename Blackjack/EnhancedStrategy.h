#pragma once
#include "BasicStrategy.h"

class EnhancedStrategy :
	public BasicStrategy
{
public:
	int MakeDecision(Hand handCurrent, bitset <5> allowSet, Table table);

	EnhancedStrategy(void);
	~EnhancedStrategy(void);
};
