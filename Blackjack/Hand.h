#pragma once
#include "Blackjack.h"
#include "Card.h"
#include "Game.h"

using namespace GameTerm;

class Hand
{
protected:
	int iSoftScore;

public:
	vector <Card> vCard;

	int iScore;
	int iStatus;

	double iBid;

	void GetOneCard(class Card);
	void CleanHands(void);

	Hand(void);
	~Hand(void);
};
