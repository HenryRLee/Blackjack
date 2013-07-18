#pragma once
#include "Blackjack.h"
#include "Card.h"
#include "GameTerm.h"

using namespace GameTerm;

class Hand
{
protected:
	int iScore;
	int iSoftScore;

public:
	vector <Card> vCard;

	int iStatus;

	double iBid;

	int GetScore(void);
	bool IsScoreSoft(void);

	void GetOneCard(class Card);
	Card RemoveLastCard(void);

	void CleanHands(void);

	Hand(void);
	~Hand(void);
};
