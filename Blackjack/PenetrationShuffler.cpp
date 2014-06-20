#include "PenetrationShuffler.h"

void PenetrationShuffler::ShuffleCards(void)
{
	if (vUsedCard.size() > iDeckNumber * CardNumInDeck * fPenetration)
	{
		for (int i=0; i<vUsedCard.size(); i++)
		{
			vCard.push_back(vUsedCard[i]);
		}

		vUsedCard.clear();
	}
	else
	{
	}
}

PenetrationShuffler::PenetrationShuffler(void)
{
}

PenetrationShuffler::PenetrationShuffler(int iDeckNumber)
{
}

PenetrationShuffler::~PenetrationShuffler(void)
{
}
