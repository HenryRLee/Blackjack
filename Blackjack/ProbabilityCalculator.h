#pragma once
#include "Blackjack.h"
#include "UsedCard.h"

class ProbabilityCalculator
{
protected:
	bool bResplitAces;
	int iMaxTimesSplitted;
	bool bHitOnSoft17;
	bool bSurrenderVsDealerAce;
	bool bDOBO;
	bool bSOBO;
	int iDeckNumber;

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

