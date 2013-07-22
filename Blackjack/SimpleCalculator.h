#pragma once
#include "ProbabilityCalculator.h"

class SimpleCalculator :
	public ProbabilityCalculator
{
protected:
	double ProbOfGettingCard(int value=0);

	bool DealerHits(HandScore handDealer);
	HandScore GetOneCard(HandScore hand, int iCardValue);

	ProbSet ProbOfHandsDealerTurn(HandScore player, HandScore dealer);

	ProbSet ProbOfHandsPlayerTurn(HandScore player, HandScore dealer);

	ProbSet ProbAfterGettingCard(ProbSet current, ProbSet next, int iCardValue);

public:
	void ShowProbSet(int iPlayerScore, bool bPlayerSoft, int iDealerScore,
			bool bDealerSoft, Table * table=NULL);

	SimpleCalculator(void);
	~SimpleCalculator(void);
};
