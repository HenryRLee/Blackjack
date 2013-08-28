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

inline int RunMultipleGames(long long times, Table * table, Player * player,
		Statistics * stat=NULL)
{
	long long peak = player->ShowBudget();
	long long dip = player->ShowBudget();

	for (long long i=0; i<times; i++)
	{
		long long current;
		
		table->StartOneGame();

		current = player->ShowBudget();

		peak = (peak > current) ? peak : current;
		dip = (dip < current) ? dip : current;
	}

	cout << "Peak: " << peak << "\tDip: " << dip;
	cout << "\tCurrent: " << player->ShowBudget();
	cout << endl;
}

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

	Hank->JoinTable(Venetian);
	Hank->UseStrategy(BStrategy);
//	Hank->UseStrategy(UserInput);
	Hank->FixBet(100);
	Hank->SetBudget(0);
	BJDealer->JoinTable(Venetian);
	MacauGame->UseStatistics(NoLogger);
//	MacauGame->UseStatistics(Logger);
	Venetian->UseGameType(MacauGame);

	Player * Passenger[10];

	for (int i=0; i<4; i++)
	{
		Passenger[i] = new Player("Passenger");
		Passenger[i]->JoinTable(Venetian);
		Passenger[i]->UseStrategy(BStrategy);
		Passenger[i]->FixBet(100);
		Passenger[i]->SetBudget(0);
	}

	Venetian->CleanTable();
//	Venetian->StartOneGame();

	cout << fixed;
	cout.precision(0);

//	Venetian->StartMultipleGames(10);

	for (int i=0; i<1000; i++)
	{
		srand(time(NULL));
		cout << "Round: " << i+1 << "\t";
		RunMultipleGames(1000, Venetian, Hank);
	}

	cout << "Final budget " << Hank->ShowBudget() << endl;

	return 0;
}
