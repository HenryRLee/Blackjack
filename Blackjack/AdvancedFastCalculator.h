#pragma once
#include "SimpleFastCalculator.h"

class AdvancedFastCalculator :
	public SimpleFastCalculator
{
protected:
	double pbCard[12];
	inline void InitiateProbOfCard(UsedCard *);

	inline double ProbOfGettingCard(int value=0);

public:
	void ShowProbSet(int iPlayerScore, bool bPlayerSoft, int iDealerScore,
			bool bDealerSoft, UsedCard * usedcard);

	AdvancedFastCalculator(void);
	~AdvancedFastCalculator(void);
};
