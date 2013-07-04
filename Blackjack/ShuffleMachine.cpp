#include "ShuffleMachine.h"

int ShuffleMachine::SetDeckNumber(int num)
{
	iDeckNumber = num;
	iTotalCardNumber = iDeckNumber * CardNumInDeck;
	return num;
}

ShuffleMachine::ShuffleMachine(void)
{
}

ShuffleMachine::~ShuffleMachine(void)
{
}
