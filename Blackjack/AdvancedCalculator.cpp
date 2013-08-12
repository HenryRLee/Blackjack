#include "AdvancedCalculator.h"
#include "UsedCard.h"

void AdvancedCalculator::InitiateProbOfCard(UsedCard * usedcard)
{
	vector <Card> vCard;

	for (int i=2; i<=11; i++)
	{
		iCount[i] = 24;
	}

	/* iCount[0] marks the total counts */
	iCount[0] = 312;
	iCount[10] = 96;

	if (usedcard != NULL)
	{
		vCard = usedcard->ShowCards();

		for (int i=0; i<vCard.size(); i++)
		{
			int value;
			value = vCard[i].GetValue();

			iCount[value]--;
			iCount[0]--;
		}
	}
}

double AdvancedCalculator::ProbOfGettingCard(int value)
{
	double prob;
	
	if ((value >= 2) && (value <= 11))
	{
		prob = (double)iCount[value]/(double)iCount[0];
	}

	return prob;
}

void AdvancedCalculator::ShowProbSetByAction(int iPlayerScore, 
		bool bPlayerSoft, int iDealerScore, bool bDealerSoft, 
		UsedCard * usedcard)
{
	InitiateProbOfCard(usedcard);
	SimpleCalculator::ShowProbSetByAction(iPlayerScore, bPlayerSoft, 
			iDealerScore, bDealerSoft, usedcard);
}

void AdvancedCalculator::ShowProbSetByNextCard(int iPlayerScore, 
		bool bPlayerSoft, int iDealerScore, bool bDealerSoft, 
		UsedCard * usedcard)
{
	InitiateProbOfCard(usedcard);
	SimpleCalculator::ShowProbSetByNextCard(iPlayerScore, bPlayerSoft, 
			iDealerScore, bDealerSoft, usedcard);
}

AdvancedCalculator::AdvancedCalculator(void)
{
}

AdvancedCalculator::~AdvancedCalculator(void)
{
}
