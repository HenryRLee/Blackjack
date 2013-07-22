#pragma once
#include "Blackjack.h"
#include "Table.h"

struct ProbSet
{
	double dWin;
	double dLose;
	double dPush;
};

class ProbabilityCalculator
{
protected:

public:
	virtual void ShowProbSet(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, Table * table=NULL) = 0;

	ProbabilityCalculator(void);
	~ProbabilityCalculator(void);
};
