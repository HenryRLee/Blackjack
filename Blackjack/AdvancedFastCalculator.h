#pragma once
#include "SimpleFastCalculator.h"

class AdvancedFastCalculator :
	public SimpleFastCalculator
{
protected:
	double pbCard[12];
	void InitiateProbOfCard(UsedCard *);

	double ProbOfGettingCard(int value=0);

public:
	void ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, UsedCard * usedcard);

	void ShowProbSetByNextCard(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, UsedCard * usedcard=NULL);

	AdvancedFastCalculator(void);
	~AdvancedFastCalculator(void);
};
