#pragma once
#include "Strategy.h"

class NoStrategy :
	public Strategy
{
protected:
	void OutputDialogue(bitset <5> allowSet);
	int InputSelection(bitset <5> allowSet);

public:
	int MakeDecision(Hand handCurrent, bitset <5> allowSet, Table table);

	NoStrategy(void);
	~NoStrategy(void);
};
