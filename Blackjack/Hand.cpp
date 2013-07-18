#include "Hand.h"

int Hand::GetScore(void)
{
	return iScore;
}

bool Hand::IsScoreSoft(void)
{
	if (iSoftScore > 0)
		return true;
	else
		return false;
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

Card Hand::RemoveLastCard(void)
{
	int value;
	Card pop = vCard.back();

	vCard.pop_back();

	/* Because the Ace value varies, we have to recount the value from start. */
	iScore = 0;
	iSoftScore = 0;

	for (int i=0; i<vCard.size(); i++)
	{
		value = vCard[i].GetValue();
		iScore += value;

		if (value == 11)
			iSoftScore++;

		while ((iScore>MaxScore) && (iSoftScore>0))
		{
			iSoftScore--;
			iScore -= 10;
		}
	}

	return pop;
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
