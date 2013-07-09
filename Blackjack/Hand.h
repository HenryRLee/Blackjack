#pragma once
#include "Blackjack.h"
#include "Card.h"
#include "GameTerm.h"

using namespace GameTerm;

class Hand
{
protected:

public:
	vector <Card> vCard;

	int iScore;
	int iSoftScore;

	int iStatus;

	double iBid;

	int GetScore(void);

	void GetOneCard(class Card);
	void CleanHands(void);

	Hand(void);
	~Hand(void);
};
