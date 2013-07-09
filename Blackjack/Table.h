#pragma once
#include "Blackjack.h"

class ShuffleMachine;
class Dealer;
class Player;
class Game;

class Table
{
private:
	Game * gametype;

public:
	Dealer * dealer;
	vector < class Player * > vPlayer;

	void AddDealer(Dealer *);
	void AddPlayer(Player *);
	void DelDealer(Dealer *);
	void DelPlayer(Player *);

	void CleanTable(void);

	void UseGameType(Game *);
	void StartOneGame(void);

	Table(void);
	~Table(void);
};
