#pragma once
#include "Blackjack.h"
#include "Deck.h"

class ShuffleMachine
{
protected:
	int iDeckNumber;
	int iTotalCardNumber;
	float fPenetration;

public:
	int SetDeckNumber(int num);
	int SetPenetration(float penetration);

	virtual Card PopOneCard(void) = 0;
	virtual void ShuffleCards(void) = 0;
	virtual int TakeSpecificCard(int value, int num = 1) = 0;

	ShuffleMachine(void);
	virtual ~ShuffleMachine(void);
};
