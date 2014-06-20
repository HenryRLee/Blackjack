#include "MacauSimulation.h"
#include "ContinuousShufflingMachine.h"
#include "ManipulatedCardSequence.h"
#include "PenetrationShuffler.h"

MacauSimulation::MacauSimulation(void)
{
	shuffler = new PenetrationShuffler(6);
//	shuffler = new ContinuousShufflingMachine(6);
//	shuffler = new ManipulatedCardSequence;

	shuffler->SetPenetration(0.16666);

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
	bResplitAces = true;
	bStandAfterSplittedAces = false;
	bLateSurrender = false;
	bSurrenderVsDealerAce = false;
	iTimesSplittedAllow = 3;
	dBlackJackPays = 2.5;
	bDOBO = true;
	bSOBO = false;
}

MacauSimulation::~MacauSimulation(void)
{
}
