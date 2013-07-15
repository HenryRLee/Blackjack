#pragma once
#include "Strategy.h"

class NoStrategy :
	public Strategy
{
protected:
	void OutputDialogue(bitset <5> allowset);
	int InputSelection(bitset <5> allowset);

public:
	int MakeDecision(Hand handCurrent, bitset <5> allowset, Table table);

	NoStrategy(void);
	~NoStrategy(void);
};
