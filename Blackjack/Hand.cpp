#include "Hand.h"

void Hand::GetOneCard(Card card)
{
	vCard.push_back(card);
	iScore += card.GetValue();
}

void Hand::CleanHands(void)
{
	vCard.clear();
	iScore = 0;
	iBid = 0;
	iStatus = WAITING;
}

Hand::Hand(void)
{
}

Hand::~Hand(void)
{
}
