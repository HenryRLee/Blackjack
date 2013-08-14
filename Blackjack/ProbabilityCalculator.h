#pragma once
#include "Blackjack.h"
#include "UsedCard.h"

class ProbabilityCalculator
{
protected:

public:
	virtual void ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL) = 0;

	virtual void ShowProbSetByNextCard(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL) = 0;

	ProbabilityCalculator(void);
	~ProbabilityCalculator(void);
};

