#pragma once
#include "ContinuousShufflingMachine.h"

class PenetrationShuffler :
	public ContinuousShufflingMachine
{
private:

public:
	void ShuffleCards(void);

	PenetrationShuffler(void);
	PenetrationShuffler(int iDeckNumber);
	~PenetrationShuffler(void);
};
