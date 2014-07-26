#pragma once
#include "UsedCard.h"
#include <iostream>
#include <vector>
using namespace std;

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

	enum PlayerAction
	{
		NONE, HIT, STAND, DOUBLE, SPLIT, SURRENDER,
	};

public:
	virtual void ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL) = 0;

	virtual void ShowProbSetByNextCard(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL) = 0;

	virtual void ShowDeltaOfEachTakenCard(int iPlayerScore, bool bPlayerSoft,
			int iDealerScore, bool bDealerSoft, int iFirstAction=HIT,
			int iSecondAction=STAND, UsedCard * usedcard=NULL);

	ProbabilityCalculator(void);
	~ProbabilityCalculator(void);
};

