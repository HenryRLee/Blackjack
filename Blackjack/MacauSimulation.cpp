#include "MacauSimulation.h"
#include "ContinuousShufflingMachine.h"

MacauSimulation::MacauSimulation(void)
{
	shuffler = new ContinuousShufflingMachine;

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
	bDLOB = true;
	bSLOB = false;
}

MacauSimulation::~MacauSimulation(void)
{
}
