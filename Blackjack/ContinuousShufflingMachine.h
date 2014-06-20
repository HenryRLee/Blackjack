#pragma once
#include "ShuffleMachine.h"

class ContinuousShufflingMachine :
	public ShuffleMachine
{
protected:
	vector <Card> vCard;
	vector <Card> vUsedCard;
	Deck deck;

public:
	Card PopOneCard(void);

	void ShuffleCards(void);
	int TakeSpecificCard(int value, int num = 1);

	ContinuousShufflingMachine(void);
	ContinuousShufflingMachine(int iDeckNumber);
	~ContinuousShufflingMachine(void);
};
