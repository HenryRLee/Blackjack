#pragma once
#include "ContinuousShufflingMachine.h"

class PenetrationShuffler :
	public ContinuousShufflingMachine
{
private:

public:
	void ShuffleCards(void);
	void ShuffleCards(Table *);

	PenetrationShuffler(void);
	PenetrationShuffler(int iDeckNumber);
	~PenetrationShuffler(void);
};
