#pragma once
#include "Blackjack.h"

class Card
{
private:
	int id;
	unsigned int value;
	char name[8];
public:
	unsigned int GetValue(void);

	Card(void);
	Card(int id, int value, char name[]);
	~Card(void);
};

