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
		WON, LOST, PUSH, BJ, WAITING, BUSTED, SURRENDERED
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
	void OneHandRoutine(Dealer * , vector < class Player * >);

	Game(void);
	virtual ~Game(void);
};
