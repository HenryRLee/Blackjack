#pragma once
#include "ShuffleMachine.h"

class ContinuousShufflingMachine :
	public ShuffleMachine
{
private:
	vector <Card> vCard;
	vector <Card> vUsedCard;
	Deck deck;

public:
	Card PopOneCard(void);

	void ShuffleCards(void);
	int TakeSpecificCard(int value);

	ContinuousShufflingMachine(void);
	ContinuousShufflingMachine(int iDeckNumber);
	~ContinuousShufflingMachine(void);
};
