#pragma once
#include "SimpleCalculator.h"

class StoredEv
{
public:
	double dEV;
	bool bMark;

	StoredEv(void)
	{
		dEV = 0;
		bMark = false;
	}
};

class SimpleFastCalculator :
	public SimpleCalculator
{
private:
	StoredEv sePlayer[22][22][2][2];
	StoredEv seDealer[22][22][2][2];

protected:
	ProbSet ProbOfHandsDealerTurn(HandScore player, HandScore dealer);

	ProbSet ProbOfHandsPlayerTurn(HandScore player, HandScore dealer, 
			int action=NONE);

public:
	SimpleFastCalculator(void);
	~SimpleFastCalculator(void);
};
