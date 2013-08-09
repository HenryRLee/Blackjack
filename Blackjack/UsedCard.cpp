#include "UsedCard.h"

void UsedCard::GetOneCard(Card card)
{
	vCard.push_back(card);
}

void UsedCard::GetOneCard(int value)
{
	char blank[4] = "";
	Card card(value, value, blank);
	vCard.push_back(card);
}

void UsedCard::Clear(void)
{
	vCard.clear();
}

vector <Card> UsedCard::ShowCards(void)
{
	return vCard;
}

UsedCard::UsedCard(void)
{
}

UsedCard::~UsedCard(void)
{
}
