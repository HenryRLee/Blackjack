#include "ContinuousShufflingMachine.h"

Card ContinuousShufflingMachine::PopOneCard(void)
{
	Card cardPop;
	int idx;

	idx = rand() % vCard.size();
	cardPop = vCard[idx];

	vCard.erase(vCard.begin() + idx);

	return cardPop;
}

void ContinuousShufflingMachine::ShuffleCards(void)
{
	vCard.clear();

	for (int i=0; i<iDeckNumber; i++)
	{
		for (int j=0; j<CardNumInDeck; j++)
		{
			vCard.push_back(*deck.card[j]);
		}
	}
}

ContinuousShufflingMachine::ContinuousShufflingMachine(void)
{
	SetDeckNumber(6);

	srand(time(NULL));
}

ContinuousShufflingMachine::~ContinuousShufflingMachine(void)
{
}
