#include "ContinuousShufflingMachine.h"

Card ContinuousShufflingMachine::PopOneCard(void)
{
	Card cardPop;
	int idx;

	idx = rand() % vCard.size();
	cardPop = vCard[idx];

	vUsedCard.push_back(vCard[idx]);
	vCard.erase(vCard.begin() + idx);

	return cardPop;
}

void ContinuousShufflingMachine::ShuffleCards(void)
{
	for (int i=0; i<vUsedCard.size(); i++)
	{
		vCard.push_back(vUsedCard[i]);
	}

	vUsedCard.clear();
}

ContinuousShufflingMachine::ContinuousShufflingMachine(void)
{
	SetDeckNumber(6);

	srand(time(NULL));

	vCard.clear();
	vUsedCard.clear();

	for (int i=0; i<iDeckNumber; i++)
	{
		for (int j=0; j<CardNumInDeck; j++)
		{
			vCard.push_back(*deck.card[j]);
		}
	}
}

ContinuousShufflingMachine::~ContinuousShufflingMachine(void)
{
}
