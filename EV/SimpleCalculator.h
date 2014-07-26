#pragma once
#include "ProbabilityCalculator.h"

class ProbSet;

struct HandScore
{
	int iScore;
	bool bSoft;
};

class SimpleCalculator :
	public ProbabilityCalculator
{
protected:
	enum ActionAllowed
	{
		ALLOWDOUBLE=1, ALLOWSPLIT=2,
	};

	bool bDoubled;
	int iAdditionalHand;

	virtual double ProbOfGettingCard(int value);

	bool DealerHits(HandScore handDealer);
	HandScore GetOneCard(HandScore hand, int iCardValue);

	ProbSet ProbOfHandsDealerTurn(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsDealerFirstTurn(HandScore player, HandScore dealer);

	ProbSet ProbOfHandsPlayerTurn(HandScore player, HandScore dealer, 
			int action=NONE);

	virtual ProbSet ProbOfHandsPlayerHit(HandScore player, HandScore dealer);
	virtual ProbSet ProbOfHandsPlayerStand(HandScore player, HandScore dealer);
	virtual ProbSet ProbOfHandsPlayerHitOrStand(HandScore player,
			HandScore dealer);
	virtual ProbSet ProbOfHandsPlayerDouble(HandScore player, HandScore dealer);
	virtual ProbSet ProbOfHandsPlayerSplit(HandScore player, HandScore dealer,
			int iTimesSplitted);

	virtual ProbSet ProbOfHandsPlayerAction(HandScore player, HandScore dealer,
			int action);

	ProbSet ProbAfterGettingCard(ProbSet current, ProbSet next, int iCardValue);

public:
	void ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL);

	void ShowProbSetByNextCard(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, int action=0,
			UsedCard * usedcard=NULL);

	SimpleCalculator(void);
	~SimpleCalculator(void);
};


class ProbSet
{
public:
	/*
	double dWin;
	double dLose;
	double dPush;
	*/
	double dEV;

	ProbSet(void)
	{
		/*
		dWin = 0;
		dLose = 0;
		dPush = 0;
		*/
		dEV = 0;
	}

};
