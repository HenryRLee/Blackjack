#include "ProbabilityCalculator.h"

void ProbabilityCalculator::ShowDeltaOfEachTakenCard(int iPlayerScore,
		bool bPlayerSoft, int iDealerScore, bool bDealerSoft,
		int iFirstAction, int iSecondAction, UsedCard * usedcard)
{
}

ProbabilityCalculator::ProbabilityCalculator(void)
{
	iMaxTimesSplitted = 3;
	bResplitAces = false;
	bHitOnSoft17 = false;
	bSurrenderVsDealerAce = false;
	bDOBO = true;
	bSOBO = true;
	iDeckNumber = 6;
}

ProbabilityCalculator::~ProbabilityCalculator(void)
{
}
