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
private:
	bool ResplitAces;
	int iMaxTimesSplitted;

protected:
	enum PlayerAction
	{
		NONE, HIT, STAND,
	};

	virtual double ProbOfGettingCard(int value);

	inline double CalEdge(ProbSet);

	inline bool DealerHits(HandScore handDealer);
	HandScore GetOneCard(HandScore hand, int iCardValue);

	ProbSet ProbOfHandsDealerTurn(HandScore player, HandScore dealer);

	ProbSet ProbOfHandsPlayerTurn(HandScore player, HandScore dealer, 
			int action=NONE);

	ProbSet ProbOfHandsPlayerHit(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsPlayerStand(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsPlayerHitOrStand(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsPlayerDouble(HandScore player, HandScore dealer);
	ProbSet ProbOfHandsPlayerSplit(HandScore player, HandScore dealer, 
			int iTimesSplitted);

	ProbSet ProbAfterGettingCard(ProbSet current, ProbSet next, int iCardValue);

public:
	void ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, UsedCard * usedcard=NULL);

	void ShowProbSetByNextCard(int iPlayerScore, bool bPlayerSoft, 
			int iDealerScore, bool bDealerSoft, UsedCard * usedcard=NULL);

	SimpleCalculator(void);
	~SimpleCalculator(void);
};


class ProbSet
{
public:
	double dWin;
	double dLose;
	double dPush;
	double dEV;

	ProbSet(void)
	{
		dWin = 0;
		dLose = 0;
		dPush = 0;
		dEV = 0;
	}

};
