#include "Blackjack.h"
#include "Player.h"
#include "Dealer.h"
#include "Table.h"
#include "MacauSimulation.h"
#include "StreamLog.h"

int main(int argc, char *argv[])
{
	Gambler * Hank = new Player("Hank");
	Gambler * BJDealer = new Dealer("BJDealer");
	Table * Venetian = new Table;
	Game * MacauGame = new MacauSimulation;
	Statistics * Logger = new StreamLog;

	Hank->JoinTable(Venetian);
	BJDealer->JoinTable(Venetian);
	MacauGame->UseStatistics(Logger);
	Venetian->UseGameType(MacauGame);

	Venetian->StartOneGame();

	return 0;
}
