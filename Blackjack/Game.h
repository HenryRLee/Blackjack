#pragma once
#include "Blackjack.h"
#include "GameTerm.h"

using namespace GameTerm;

class Table;
class Gambler;
class Player;
class Dealer;
class ShuffleMachine;

class Game
{
protected:
	ShuffleMachine *shuffler;

	bool bHitOnSoft17;
	bool bDouble;
	bool bSurrender;
	bool bSplit;
	bool bHitAfterSplit;
	bool bHitAfterDouble;
	bool bDoubleAfterHit;
	bool bDoubleAfterDouble;
	bool bDoubleAfterSplit;
	bool bSplitAfterSplit;
	bool bLateSurrender;
	int iTimesSplittedAllow;
	double dBlackJackPays;

	void inline DealInitialCards(Dealer *, vector < class Player * >);
	void inline DealOneCard(Gambler *, int hand=0);
	void PlayerAction(Player *, bitset<5> allowset, int hand=0);
	void DealerAction(Dealer *);

public:
	void OneHandRoutine(Dealer * , vector < class Player * >, Table *);

	Game(void);
	virtual ~Game(void);
};
