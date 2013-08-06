#include "AdvancedFastCalculator.h"
#include "UsedCard.h"

inline void AdvancedFastCalculator::InitiateProbOfCard(UsedCard * usedcard)
{
	vector <Card> vCard;
	int count[12] = {0};		// Use count[0] for total count

	vCard = usedcard->ShowCards();

	for (int i=0; i<vCard.size(); i++)
	{
		int value;
		value = vCard[i].GetValue();

		count[value]++;
		count[0]++;
	}

	for (int i=2; i<=11; i++)
	{
		pbCard[i] = (double)count[i]/(double)count[0];
	}
}

inline double AdvancedFastCalculator::ProbOfGettingCard(int value)
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

AdvancedFastCalculator::AdvancedFastCalculator(void)
{
}

AdvancedFastCalculator::~AdvancedFastCalculator(void)
{
}
