#include "Hand.h"

int Hand::GetScore(void)
{
	return iScore;
}

void Hand::GetOneCard(Card card)
{
	int value;

	value = card.GetValue();
	vCard.push_back(card);
	iScore += value;

	if (value == 11)
		iSoftScore++;

	while ((iScore>MaxScore) && (iSoftScore>0))
	{
		iSoftScore--;
		iScore -= 10;
	}

}

void Hand::CleanHands(void)
{
	vCard.clear();
	iScore = 0;
	iBid = 0;
	iStatus = WAITING;
	iSoftScore = 0;
}

Hand::Hand(void)
{
	vCard.clear();
	iScore = 0;
	iBid = 0;
	iStatus = WAITING;
	iSoftScore = 0;
}

Hand::~Hand(void)
{
}
