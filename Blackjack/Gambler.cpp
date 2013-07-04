#include "Gambler.h"

void Gambler::GetOneCard(Card card, int hand)
{
	vHand[hand].GetOneCard(card);
}

void Gambler::CleanHands(int hand)
{
	vHand[hand].CleanHands();
}

Gambler::Gambler(void)
{
}

Gambler::~Gambler(void)
{
}
