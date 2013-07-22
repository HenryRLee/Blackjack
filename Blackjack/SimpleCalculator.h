#pragma once
#include "ProbabilityCalculator.h"

class SimpleCalculator :
	public ProbabilityCalculator
{
protected:
	double ProbOfGettingCard(int value=0);

	bool DealerHits(int iDealerScore, bool bDealerSoft);
	void GetOneCard(int & iScore, bool & bSoft, int iCardValue);

	ProbSet ProbOfHandsDealerTurn(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft);

	ProbSet ProbOfHandsPlayerTurn(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft);

	ProbSet ProbOfNextCard(ProbSet setNextCard, int iNextCardValue);

public:
	void ShowProbSet(int iPlayerScore, bool bPlayerSoft, int iDealerScore,
			bool bDealerSoft, Table * table=NULL);

	SimpleCalculator(void);
	~SimpleCalculator(void);
};
