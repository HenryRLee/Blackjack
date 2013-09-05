#pragma once
#include "SimpleCalculator.h"

class AdvancedCalculator :
	public SimpleCalculator
{
protected:
	vector <int> vInitialCount;
	void InitiateCardCounts(UsedCard *);
	vector <int> CardFlowing(int value, vector <int> vRemaining);

	double ProbOfGettingCard(int value);
	double ProbOfGettingCard(int value, vector <int> vRemaining);

	ProbSet ProbOfHandsDealerTurn(HandScore player, HandScore dealer,
			vector <int> vRemaining);
	ProbSet ProbOfHandsDealerFirstTurn(HandScore player, HandScore dealer,
			vector <int> vRemaining, bool bLoseBJ=true);

	ProbSet ProbOfHandsPlayerTurn(HandScore player, HandScore dealer, 
			vector <int> vRemaining, int action=NONE);

	ProbSet ProbOfHandsPlayerHit(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsPlayerStand(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsPlayerHitOrStand(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsPlayerDouble(HandScore player, HandScore dealer);

	ProbSet ProbAfterGettingCard(ProbSet current, ProbSet next, int iCardValue,
			vector <int> vRemaining);

public:
	void ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL);

	void ShowProbSetByNextCard(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL);

	AdvancedCalculator(void);
	~AdvancedCalculator(void);
};
