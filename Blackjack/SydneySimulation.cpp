#include "SydneySimulation.h"
#include "ContinuousShufflingMachine.h"
#include "ManipulatedCardSequence.h"
#include "PenetrationShuffler.h"

SydneySimulation::SydneySimulation(void)
{
	shuffler = new PenetrationShuffler(8);
//	shuffler = new ContinuousShufflingMachine(6);
//	shuffler = new ManipulatedCardSequence;

	shuffler->SetPenetration(0.375);

	bHitOnSoft17 = false;
	bDouble = true;
	bSurrender = false;
	bSplit = true;
	bDealerTakesHole = false;
	bDealerPeaksHole = false;
	bDealerPeaksHoleOnAce = false;
	bDealerPeaksHoleOnTen = false;
	bHitAfterSplit = true;
	bDoubleAfterSplit = true;
	bDoubleOnAnyTwo = false;
	bDoubleOnNine = true;
	bDoubleOnTen = true;
	bDoubleOnEleven = true;
	bSplitAfterSplit = false;
	bResplitAces = false;
	bStandAfterSplittedAces = true;
	bLateSurrender = false;
	bSurrenderVsDealerAce = false;
	iTimesSplittedAllow = 1;
	dBlackJackPays = 2.5;
	bDOBO = true;
	bSOBO = true;
}

SydneySimulation::~SydneySimulation(void)
{
}
