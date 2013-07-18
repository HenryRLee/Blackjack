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

	ContinuousShufflingMachine(void);
	~ContinuousShufflingMachine(void);
};
