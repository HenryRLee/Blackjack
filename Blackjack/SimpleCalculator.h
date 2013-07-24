#pragma once
#include "ProbabilityCalculator.h"

class SimpleCalculator :
	public ProbabilityCalculator
{
private:
	bool ResplitAces;
	int iMaxTimesSplitted;

protected:
	enum PlayerAction
	{
		NONE, HIT, STAND,
	};

	double ProbOfGettingCard(int value=0);

	double CalEdge(ProbSet);

	bool DealerHits(HandScore handDealer);
	HandScore GetOneCard(HandScore hand, int iCardValue);

	ProbSet ProbOfHandsDealerTurn(HandScore player, HandScore dealer);

	ProbSet ProbOfHandsPlayerTurn(HandScore player, HandScore dealer, 
			int action=NONE);

	ProbSet ProbOfHandsPlayerDouble(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsPlayerSplit(HandScore player, HandScore dealer, 
			int iTimesSplitted);

	ProbSet ProbAfterGettingCard(ProbSet current, ProbSet next, 
			int iCardValue, double multiplier=1);

public:
	void ShowProbSet(int iPlayerScore, bool bPlayerSoft, int iDealerScore,
			bool bDealerSoft, Table * table=NULL);

	SimpleCalculator(void);
	~SimpleCalculator(void);
};
