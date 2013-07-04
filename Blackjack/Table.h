#pragma once
#include "Blackjack.h"

class ShuffleMachine;
class Dealer;
class Player;

class Table
{
private:


public:
	Dealer * dealer;
	vector < class Player * > vPlayer;

	void AddDealer(Dealer *);
	void AddPlayer(Player *);
	void DelDealer(Dealer *);
	void DelPlayer(Player *);

	Table(void);
	~Table(void);
};
