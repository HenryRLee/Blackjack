#pragma once
#include "Blackjack.h"
#include "Deck.h"

class ShuffleMachine
{
protected:
	int iDeckNumber;
	int iTotalCardNumber;

public:
	int SetDeckNumber(int num);

	virtual Card PopOneCard(void) = 0;
	virtual void ShuffleCards(void) = 0;
	virtual int TakeSpecificCard(int value) = 0;

	ShuffleMachine(void);
	virtual ~ShuffleMachine(void);
};
