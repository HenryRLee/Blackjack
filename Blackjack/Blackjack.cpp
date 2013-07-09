#include "Blackjack.h"
#include "Player.h"
#include "Dealer.h"
#include "Table.h"
#include "MacauSimulation.h"

int main(int argc, char *argv[])
{
	Gambler * Hank = new Player("Hank");
	Gambler * BJDealer = new Dealer("BJDealer");
	Table * Venetian = new Table;
	Game * MacauGame = new MacauSimulation;

	Hank->JoinTable(Venetian);
	BJDealer->JoinTable(Venetian);
	Venetian->UseGameType(MacauGame);

	Venetian->StartOneGame();

	return 0;
}
