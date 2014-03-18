#pragma once
#include "Gambler.h"

class Dealer :
	public Gambler
{
protected:
	Card cardHole;
	int MakeDecision(bool bHitOnSoft17, int hand=0);

public:
	string ShowName(void);

	void JoinTable(Table *);

	void GetHoleCard(Card hole);
	bool PeakHoldCard(void);
	Card ShowHoleCard(void);

	Dealer(void);
	Dealer(string);
	~Dealer(void);

	friend class Game;
};
