#include "ProbabilityCalculator.h"

ProbabilityCalculator::ProbabilityCalculator(void)
{
	iMaxTimesSplitted = 3;
	bResplitAces = false;
	bHitOnSoft17 = false;
	bSurrenderVsDealerAce = false;
	bDOBO = true;
}

ProbabilityCalculator::~ProbabilityCalculator(void)
{
}
