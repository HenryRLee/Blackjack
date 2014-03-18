#include "MacauSimulation.h"
#include "ContinuousShufflingMachine.h"
#include "ManipulatedCardSequence.h"

MacauSimulation::MacauSimulation(void)
{
	shuffler = new ContinuousShufflingMachine(6);
//	shuffler = new ManipulatedCardSequence;

	bHitOnSoft17 = false;
	bDouble = true;
	bSurrender = true;
	bSplit = true;
	bDealerTakesHole = false;
	bDealerPeaksHole = false;
	bDealerPeaksHoleOnAce = false;
	bDealerPeaksHoleOnTen = false;
	bHitAfterSplit = true;
	bDoubleAfterSplit = true;
	bDoubleOnAnyTwo = true;
	bDoubleOnNine = true;
	bDoubleOnTen = true;
	bDoubleOnEleven = true;
	bSplitAfterSplit = true;
	bResplitAces = false;
	bStandAfterSplittedAces = false;
	bLateSurrender = false;
	bSurrenderVsDealerAce = false;
	iTimesSplittedAllow = 3;
	dBlackJackPays = 2.5;
	bDOBO = true;
	bSOBO = true;
}

MacauSimulation::~MacauSimulation(void)
{
}
