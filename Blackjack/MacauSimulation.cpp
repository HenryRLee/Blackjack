#include "MacauSimulation.h"
#include "ContinuousShufflingMachine.h"
#include "ManipulatedCardSequence.h"

MacauSimulation::MacauSimulation(void)
{
	shuffler = new ContinuousShufflingMachine;
//	shuffler = new ManipulatedCardSequence;

	bHitOnSoft17 = false;
	bDouble = true;
	bSurrender = true;
	bSplit = true;
	bHitAfterSplit = true;
	bHitAfterDouble = false;
	bDoubleAfterHit = false;
	bDoubleAfterDouble = false;
	bDoubleAfterSplit = true;
	bSplitAfterSplit = true;
	bResplitAces = false;
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
