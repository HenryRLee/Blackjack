#pragma once
#include "Blackjack.h"
#include "UsedCard.h"

class ProbSet;

struct HandScore
{
	int iScore;
	bool bSoft;
};

class ProbabilityCalculator
{
protected:

public:
	virtual void ShowProbSet(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, UsedCard * usedcard=NULL) = 0;

	virtual void ShowProbSetDetail(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, UsedCard * usedcard=NULL) = 0;

	ProbabilityCalculator(void);
	~ProbabilityCalculator(void);
};

class ProbSet
{
public:
	double dWin;
	double dLose;
	double dPush;
	double dEV;

	ProbSet(void)
	{
		dWin = 0;
		dLose = 0;
		dPush = 0;
		dEV = 0;
	}

};
