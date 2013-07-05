#pragma once
#include "Blackjack.h"

class Gambler;
class Player;
class Dealer;
class ShuffleMachine;

namespace GameTerm
{
	enum Action
	{
		HIT, STAND, DOUBLE, SPLIT, SURRENDER
	};

	enum Status
	{
		WON, LOST, PUSH, BJ, WAITING, BUSTED
	};

	enum
	{
		MaxTimesSplitted = 7,
		MaxHands= 8,
		MaxScore = 21
	};

};

class Game
{
protected:
	ShuffleMachine *shuffler;

	void inline DealInitialCards(Dealer *, vector < class Player * >);
	void inline DealOneCard(Gambler *);
	void PlayerAction(Player *, bitset<5> allowset, int hand=0);

public:
	void OneHandRoutine(Dealer * , vector < class Player * >);

	Game(void);
	virtual ~Game(void);
};
