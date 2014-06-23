#include "FlowCounting.h"
#include "Table.h"

long long FlowCounting::CalculateBet(long long iPreferredBet, long long iBudget,
		Table *table)
{
	if (table)
	{
		long long iFinalBet = iPreferredBet;
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

		for (int i=0; i<vUsedCard.size(); i++)
		{
			int score = cardvUsedCard[i].GetValue();
			if (score <= 11)
				iFlowValue += iCardValue[score];
		}

		cout << iFlowValue << endl;;
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
