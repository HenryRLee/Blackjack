#include "ProbabilityCalculator.h"

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
