#include "Gambler.h"

void Gambler::GetOneCard(Card card, int hand)
{
	if (vHand.size() < 1)
	{
		Hand firsthand;
		vHand.push_back(firsthand);
	}

	if (vHand.size() > hand)
	{
		vHand[hand].GetOneCard(card);
	}
}

void Gambler::CleanHands(void)
{
	for (int i=0; i<vHand.size(); i++)
	{
		vHand[i].CleanHands();
	}

	vHand.clear();
}

Gambler::Gambler(void)
{
}

Gambler::~Gambler(void)
{
}
