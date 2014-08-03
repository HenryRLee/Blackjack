#include "ProbabilityCalculator.h"

void ProbabilityCalculator::ShowDeltaOfEachTakenCard(int iPlayerScore,
		bool bPlayerSoft, int iDealerScore, bool bDealerSoft,
		int iFirstAction, int iSecondAction, UsedCard * usedcard)
{
}

ProbabilityCalculator::ProbabilityCalculator(void)
{
	iMaxTimesSplitted = 1;
	bResplitAces = false;
	bHitOnSoft17 = false;
	bDOBO = true;
	bSOBO = false;
	iDeckNumber = 6;
	bDoubleOnAnyTwo = false;
	bDoubleOnSoft = false;
	bDoubleOnNine = true;
	bDoubleOnTen = true;
	bDoubleOnEleven = true;
	bStandAfterSplittedAces = true;
}

ProbabilityCalculator::~ProbabilityCalculator(void)
{
}
