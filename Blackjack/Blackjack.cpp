#include "Blackjack.h"
#include "Player.h"
#include "Dealer.h"
#include "Table.h"
#include "MacauSimulation.h"
#include "StreamLog.h"
#include "NoStrategy.h"

int main(int argc, char *argv[])
{
	Player * Hank = new Player("Hank");
	Dealer * BJDealer = new Dealer("BJDealer");
	Table * Venetian = new Table;
	Game * MacauGame = new MacauSimulation;
	Statistics * Logger = new StreamLog;
	Strategy * UserInput = new NoStrategy;

	Hank->JoinTable(Venetian);
	Hank->UseStrategy(UserInput);
	BJDealer->JoinTable(Venetian);
	MacauGame->UseStatistics(Logger);
	Venetian->UseGameType(MacauGame);

	Venetian->CleanTable();
	Venetian->StartOneGame();

	return 0;
}
