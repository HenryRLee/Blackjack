#include <iostream>
#include "SimpleCalculator.h"

using namespace std;

int main(int argc, char * argv[])
{
	ProbabilityCalculator * cal = new SimpleCalculator;

	if (argc == 3)
	{
		cal->ShowProbSet(atoi(argv[1]), false, atoi(argv[2]), false);
	}
	else if (argc >= 5)
	{
		bool bPlayerSoft;
		bool bDealerSoft;

		if (strcmp(argv[3], "1") == 0)
			bPlayerSoft = true;
		else
			bPlayerSoft = false;

		if (strcmp(argv[4], "1") == 0)
			bDealerSoft = true;
		else
			bDealerSoft = false;

		cal->ShowProbSet(atoi(argv[1]), bPlayerSoft, atoi(argv[2]), 
				bDealerSoft);
	}
	else
	{
		int iPlayerScore;
		int iDealerScore;
		int iPlayerSoft;
		int iDealerSoft;
		bool bPlayerSoft;
		bool bDealerSoft;

		cout << "Usage" << endl;
		cout << "EV <Player Score> <Dealer Score> ";
		cout << "[<Player Score is Soft> <Delaer Score is Soft>]" << endl;
		cout << "Player Score [2-21] ";
		cin >> iPlayerScore;
		cout << "Dealer Score [2-21] ";
		cin >> iDealerScore;
		cout << "Player Score is Soft [0-1] ";
		cin >> iPlayerSoft;
		cout << "Dealer Score is Soft [0-1] ";
		cin >> iDealerSoft;

		if (iPlayerSoft == 1)
			bPlayerSoft = true;
		else
			bDealerSoft = false;

		if (iDealerSoft == 1)
			bDealerSoft = true;
		else
			bDealerSoft = false;

		cal->ShowProbSet(iPlayerScore, bPlayerSoft, iDealerScore, 
				bDealerSoft);
	}

	return 0;
}
