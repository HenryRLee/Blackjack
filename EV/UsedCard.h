#pragma once
#include "Card.h"

class UsedCard
{
private:
	vector <Card> vCard;

public:
	void GetOneCard(Card card);
	void GetOneCard(int value);
	void Clear(void);
	vector <Card> ShowCards(void);

	UsedCard(void);
	~UsedCard(void);
};

