#pragma once
#include "Blackjack.h"
#include "Card.h"

class ShuffleMachine;
class Dealer;
class Player;
class Game;

class Table
{
private:
	Game * gametype;

	vector <Card> vUsedCards;

	void AddDealer(Dealer *);
	void AddPlayer(Player *);
	void DelDealer(Dealer *);
	void DelPlayer(Player *);

public:
	Dealer * dealer;
	vector <class Player *> vPlayer;

	void CleanTable(void);

	void GetOneCard(Card card);
	vector <Card> ShowUsedCards(void);

	void UseGameType(Game *);
	void StartOneGame(void);
	void StartMultipleGames(long long num=1000);

	Table(void);
	~Table(void);

	friend class Player;
	friend class Dealer;
};
