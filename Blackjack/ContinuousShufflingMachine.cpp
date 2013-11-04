#include "ContinuousShufflingMachine.h"
#include <random>

std::random_device generator;

Card ContinuousShufflingMachine::PopOneCard(void)
{
	Card cardPop;
	int idx;

	std::uniform_int_distribution<int> distribution(0, vCard.size()-1);
//	idx = rand() % vCard.size();
	idx = distribution(generator);
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

ContinuousShufflingMachine::ContinuousShufflingMachine(int iDeckNumber)
{
	SetDeckNumber(iDeckNumber);

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
