#pragma once
#include "Blackjack.h"

class Card
{
private:
	int id;
	unsigned int value;
	string name;
public:
	unsigned int GetValue(void);
	string GetName(void);

	Card(void);
	Card(int id, int value, char name[]);
	~Card(void);
};

