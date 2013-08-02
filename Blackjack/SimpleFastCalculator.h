#pragma once
#include "SimpleCalculator.h"

class StoredEv;

class SimpleFastCalculator :
	public SimpleCalculator
{
public:
	SimpleFastCalculator(void);
	~SimpleFastCalculator(void);
};

class StoredEv
{
public:
	double dEV;
	bool bSet;

	StoredEv(void)
	{
		dEV = 0;
		bSet = false;
	}
};
