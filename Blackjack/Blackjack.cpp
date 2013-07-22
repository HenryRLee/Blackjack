#include "Blackjack.h"
#include "Player.h"
#include "Dealer.h"
#include "Table.h"
#include "MacauSimulation.h"
#include "StreamLog.h"
#include "LongTermStats.h"
#include "NoStrategy.h"
#include "BasicStrategy.h"
#include "SimpleCalculator.h"

int main(int argc, char *argv[])
{
	Player * Hank = new Player("Hank");
	Dealer * BJDealer = new Dealer("BJDealer");
	Table * Venetian = new Table;
	Game * MacauGame = new MacauSimulation;
	Statistics * NoLogger = new LongTermStats;
	Statistics * Logger = new StreamLog;
	Strategy * UserInput = new NoStrategy;
	Strategy * BStrategy = new BasicStrategy;
	ProbabilityCalculator * cal = new SimpleCalculator;

	/*
	Hank->JoinTable(Venetian);
	Hank->UseStrategy(BStrategy);
	Hank->FixBid(100);
	Hank->SetBudget(500*1000);
	BJDealer->JoinTable(Venetian);
	MacauGame->UseStatistics(NoLogger);
	Venetian->UseGameType(MacauGame);

	Venetian->CleanTable();
	Venetian->StartOneGame();
	Venetian->StartMultipleGames(100);

	cout << fixed;
	cout << "Player budget: " << Hank->ShowBudget() << endl;
	*/

	cal->ShowProbSet(2, false, 10, false);

	return 0;
}
