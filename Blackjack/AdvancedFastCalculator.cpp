#include "AdvancedFastCalculator.h"
#include "UsedCard.h"

void AdvancedFastCalculator::InitiateProbOfCard(UsedCard * usedcard)
{
	vector <Card> vCard;
	int count[12];		// Use count[0] for total count

	for (int i=2; i<=11; i++)
	{
		count[i] = 24;
	}

	count[0] = 312;
	count[10] = 96;

	if (usedcard != NULL)
	{
		vCard = usedcard->ShowCards();

		for (int i=0; i<vCard.size(); i++)
		{
			int value;
			value = vCard[i].GetValue();

			count[value]--;
			count[0]--;
		}
	}

	for (int i=2; i<=11; i++)
	{
		pbCard[i] = (double)count[i]/(double)count[0];
	}
}

double AdvancedFastCalculator::ProbOfGettingCard(int value)
{
	double prob;
	
	if ((value >= 2) && (value <= 11))
		prob = pbCard[value];

	return prob;
}

void AdvancedFastCalculator::ShowProbSet(int iPlayerScore, bool bPlayerSoft, 
		int iDealerScore, bool bDealerSoft, UsedCard * usedcard)
{
	InitiateProbOfCard(usedcard);
	SimpleCalculator::ShowProbSet(iPlayerScore, bPlayerSoft, iDealerScore, 
			bDealerSoft, usedcard);
}

void AdvancedFastCalculator::ShowProbSetDetail(int iPlayerScore, 
		bool bPlayerSoft, int iDealerScore, bool bDealerSoft, 
		UsedCard * usedcard)
{
	InitiateProbOfCard(usedcard);
	SimpleCalculator::ShowProbSetDetail(iPlayerScore, bPlayerSoft, 
			iDealerScore, bDealerSoft, usedcard);
}

AdvancedFastCalculator::AdvancedFastCalculator(void)
{
}

AdvancedFastCalculator::~AdvancedFastCalculator(void)
{
}
