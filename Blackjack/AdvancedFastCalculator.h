#pragma once
#include "SimpleFastCalculator.h"

class AdvancedFastCalculator :
	public SimpleFastCalculator
{
protected:
	double pbCard[12];
	void InitiateProbOfCard(UsedCard *);

	double ProbOfGettingCard(int value);

public:
	void ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL);

	void ShowProbSetByNextCard(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL);

	AdvancedFastCalculator(void);
	~AdvancedFastCalculator(void);
};
