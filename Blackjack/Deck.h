#pragma once
#include "Blackjack.h"
#include "Card.h"

class Deck
{
#define CardNumInDeck	52

public:
	Card *card[CardNumInDeck];

	Deck(void);
	Deck(int idx);
	~Deck(void);
};
