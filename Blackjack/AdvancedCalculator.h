#pragma once
#include "SimpleCalculator.h"

class AdvancedCalculator :
	public SimpleCalculator
{
protected:
	int iCount[12];
	void InitiateProbOfCard(UsedCard *);

	double ProbOfGettingCard(int value=0);

public:
	void ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, UsedCard * usedcard);

	void ShowProbSetByNextCard(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, UsedCard * usedcard=NULL);

	AdvancedCalculator(void);
	~AdvancedCalculator(void);
};
