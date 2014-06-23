#include "FlowCounting.h"
#include "Table.h"

long long FlowCounting::CalculateBet(long long iPreferredBet, long long iBudget,
		Table *table)
{
	if (table)
	{
		long long iFinalBet;
		int iCardValue[12] =
		{
			0,
			0,
			79,
			89,
			115,
			148,
			87,
			56,
			-56,
			-44,
			-104,
			-122
		};
		int iFlowValue = 0;
		UsedCard vUsedCard = table->ShowUsedCards();
		vector <Card> vCard = vUsedCard.ShowCards();

		for (int i=0; i<vCard.size(); i++)
		{
			int score = vCard[i].GetValue();
			if (score <= 11)
				iFlowValue += iCardValue[score];
		}

		if (iFlowValue < -50)
			iFinalBet = 0;
		else
			iFinalBet = 100 * (iFlowValue / 100) + 1000 * (1 + iPreferredBet/1000);

		return iFinalBet;
	}
	else
	{
		return iPreferredBet;
	}
}

FlowCounting::FlowCounting(void)
{
}

FlowCounting::~FlowCounting(void)
{
}
