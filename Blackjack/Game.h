#pragma once
#include "Blackjack.h"
#include "GameTerm.h"

using namespace GameTerm;

class Table;
class Gambler;
class Player;
class Dealer;
class ShuffleMachine;
class Statistics;

class Game
{
protected:
	Table * table;
	ShuffleMachine * shuffler;
	Statistics * statistics;

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
	bool bResplitAces;
	bool bLateSurrender;
	bool bSurrenderVsDealerAce;
	/* Lose only orignal bet in double when dealer has a Blackjack */
	bool bDOBO;
	/* Lose only orignal bet in split when dealer has a Blackjack */
	bool bSOBO;
	int iTimesSplittedAllow;
	double dBlackJackPays;

	void inline DealInitialCards(Dealer *, vector <class Player *>);
	void inline DealOneCard(Gambler *, Table * table, int hand=0);
	void PlayerAction(Player *, bitset<5> allowSet, int hand=0);
	void DealerAction(Dealer *);

	void OneHandRoutine(Dealer * , vector <class Player *>, Table *);

public:

	void UseStatistics(Statistics *);

	Game(void);
	virtual ~Game(void);

	friend class Table;
};
