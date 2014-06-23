#pragma once
#include "ShuffleMachine.h"

class ManipulatedCardSequence :
	public ShuffleMachine
{
private:
	vector <Card> vCard;
	vector <Card> vUsedCard;

public:
	Card PopOneCard(void);

	void ShuffleCards(void);
	int TakeSpecificCard(int value, int num = 1);

	ManipulatedCardSequence(void);
	~ManipulatedCardSequence(void);
};
