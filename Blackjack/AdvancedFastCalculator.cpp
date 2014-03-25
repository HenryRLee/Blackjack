#include "AdvancedFastCalculator.h"
#include "UsedCard.h"

AdvancedFastCalculator::AdvancedFastCalculator(void)
{
}

AdvancedFastCalculator::~AdvancedFastCalculator(void)
{
}

bool HashItem::operator == (const HashItem item) const
{
	int cardsize;
	int productA = 1;
	int productB = 1;
	int prime[12] = {
		1,		/* 0 */
		1,		/* 1 */
		3,		/* 2 */
		5,		/* 3 */
		7,		/* 4 */
		9,		/* 5 */
		11,		/* 6 */
		13,		/* 7 */
		17,		/* 8 */
		19,		/* 9 */
		23,		/* 10 */
		2,		/* 11 */
	};

	if ((vUsedCards != item.vUsedCards)
			|| (bPlayerTurn != item.bPlayerTurn)
			|| (iPlayerScore != item.iPlayerScore)
			|| (bPlayerSoft != item.bPlayerSoft)
			|| (iDealerScore != item.iDealerScore)
			|| (bDealerSoft != item.bDealerSoft)
			|| (bAdditional != item.bAdditional)
			|| (bDoubled != item.bDoubled))
		return false;

	if (vUsedCards.size() != item.vUsedCards.size())
		return false;
	else
		cardsize = vUsedCards.size();

	for (int i=0; i<cardsize; i++)
	{
		productA *= prime[vUsedCards[i]];
		productB *= prime[item.vUsedCards[i]];
	}

	if (productA != productB)
		return false;

	return true;
}
unsigned int HashItem::HashValue(void)
{
	int box[12] = {0};
	int score;
	unsigned int hash = 1;

	if (bPlayerTurn)
	{
		/*
		 * Player score
		 * 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
		 * s12 s13 s14 s15 s16 s17 s18 s19 s20
		 * 27 at most
		 */
		if (bPlayerSoft)
			score = iPlayerScore - 4 + 10;
		else
			score = iPlayerScore - 4;

		hash = hash * 27 + score;

		/*
		 * Dealer score
		 * 2 3 4 5 6 7 8 9 10 11
		 * 10 at most
		 */
		score = iDealerScore - 2;
		
		hash = hash * 10 + score;
	}
	else
	{
		/*
		 * Make it different from player turn
		 * at most 6 * 21 in this round
		 */
		hash *= 6 * 21;

		/*
		 * Player score
		 * u16 17 18 19 20 21
		 * indifferent under 16
		 * 6 at most
		 */

		if (score <= 16)
			score = 0;
		else
			score = iPlayerScore - 16;

		hash = hash * 6 + score;

		/*
		 * Dealer score
		 * 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
		 * s12 s13 s14 s15 s16 s17
		 * skip scores above 18
		 * 21 at most
		 */
		if (bDealerSoft)
			score = iDealerScore - 2 + 5;
		else
			score = iDealerScore - 2;

		hash = hash * 21 + score;
	}
	
	hash << 1;
	if (bAdditional)
		hash += 1;

	hash << 1;
	if (bDoubled)
		hash += 1;

	for (int i=0; i<vUsedCards.size(); i++)
	{
		box[vUsedCards[i]]++;
	}

	for (int i=0; i<12; i++)
	{
		/* Assume at most 10 cards per value. If not so, it conflicts. */
		hash = hash * 10 + box[i];
	}

	return hash;
}
