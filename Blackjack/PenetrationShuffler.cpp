#include "PenetrationShuffler.h"
#include "Table.h"

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

void PenetrationShuffler::ShuffleCards(Table * table)
{
	if (vUsedCard.size() > iDeckNumber * CardNumInDeck * fPenetration)
	{
		for (int i=0; i<vUsedCard.size(); i++)
		{
			vCard.push_back(vUsedCard[i]);
		}

		vUsedCard.clear();
		table->CleanCards();
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
