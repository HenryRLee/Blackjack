#include "ShuffleMachine.h"

int ShuffleMachine::SetDeckNumber(int num)
{
	iDeckNumber = num;
	iTotalCardNumber = iDeckNumber * CardNumInDeck;
	return num;
}

void ShuffleMachine::SetPenetration(float penetration)
{
	fPenetration = penetration;
}

ShuffleMachine::ShuffleMachine(void)
{
}

ShuffleMachine::~ShuffleMachine(void)
{
}
