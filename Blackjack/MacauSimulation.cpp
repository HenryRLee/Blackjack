#include "MacauSimulation.h"
#include "ContinuousShufflingMachine.h"

MacauSimulation::MacauSimulation(void)
{
	shuffler = new ContinuousShufflingMachine;
}

MacauSimulation::~MacauSimulation(void)
{
}
