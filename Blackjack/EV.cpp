#include <iostream>
#include <string>
#include "AdvancedCalculator.h"
#include "AdvancedFastCalculator.h"

using namespace std;

bool bShowDetail;
UsedCard usedcard;

void EvMain(string arg)
{
	ProbabilityCalculator * cal = new AdvancedCalculator;
//	ProbabilityCalculator * cal = new AdvancedFastCalculator;
	string sPScore;
	string sDScore;
	string sPSoft;
	string sDSoft;
	string rest;
	size_t delim;

	delim = arg.find(" ");

	if (delim != string::npos)
	{
		sPScore = arg.substr(0, delim);
		rest = arg.substr(delim+1);
		sDScore = rest.substr(0, delim);
	}
	else
	{
		cout << "run <Player Score> <Dealer Score> [<Player is Soft> <Dealer is Soft>]" << endl;
		return;
	}

	delim = rest.find(" ");
	if (delim != string::npos)
	{
		rest = rest.substr(delim+1);

		delim = rest.find(" ");

		if (delim != string::npos)
		{
			sPSoft = rest.substr(0, delim);
			rest = rest.substr(delim+1);

			sDSoft = rest.substr(0, delim);

			if (bShowDetail)
			{
				cal->ShowProbSetByNextCard(atoi(sPScore.c_str()), 
						atoi(sPSoft.c_str()), atoi(sDScore.c_str()), 
						atoi(sDSoft.c_str()), &usedcard);
			}
			else
			{
				cal->ShowProbSetByAction(atoi(sPScore.c_str()), 
						atoi(sPSoft.c_str()), atoi(sDScore.c_str()), 
						atoi(sDSoft.c_str()), &usedcard);
			}
		}
		else
		{
			cout << "run <Player Score> <Dealer Score> [<Player is Soft> <Dealer is Soft>]" << endl;
			return;
		}
	}
	else
	{
		if (bShowDetail)
		{
			cal->ShowProbSetByNextCard(atoi(sPScore.c_str()), false, 
					atoi(sDScore.c_str()), false, &usedcard);
		}
		else
		{
			cal->ShowProbSetByAction(atoi(sPScore.c_str()), false, 
					atoi(sDScore.c_str()), false, &usedcard);
		}
	}

}

void PushCards(string arg)
{
	string cur;
	string rest;
	size_t delim;

	delim = arg.find(" ");

	if (delim != string::npos)
	{
		cur = arg.substr(0, delim);
		rest = arg.substr(delim+1);
	}
	else
	{
		cur = arg;
		rest = arg;
	}

	while(delim != string::npos)
	{
		usedcard.GetOneCard(atoi(cur.c_str()));
		delim = rest.find(" ");

		if (delim != string::npos)
		{
			cur = rest.substr(0, delim);
			rest = rest.substr(delim+1);
		}
	}

	usedcard.GetOneCard(atoi(rest.c_str()));
}

void InteractiveMode(void)
{
	string fullcmd;
	string cmdhead;
	string cmdarg;
	size_t delim;

	cout << "> ";
	getline(cin, fullcmd);

	delim = fullcmd.find(" ");

	if (delim != string::npos)
	{
		cmdhead = fullcmd.substr(0, delim);
		cmdarg = fullcmd.substr(delim+1);
	}
	else
	{
		cmdhead = fullcmd;
		cmdarg = "";
	}

	if (cmdhead.compare("run") == 0)
	{
		EvMain(cmdarg);
		InteractiveMode();
	}
	else if (cmdhead.compare("detail") == 0)
	{
		if (cmdarg.compare("off") == 0)
		{
			bShowDetail = false;
			cout << "Detail off" << endl;
		}
		else
		{
			bShowDetail = true;
			cout << "Detail on" << endl;
		}
		InteractiveMode();
	}
	else if (cmdhead.compare("pull") == 0)
	{
		PushCards(cmdarg);
		InteractiveMode();
	}
	else if (cmdhead.compare("clear") == 0)
	{
		usedcard.Clear();
		InteractiveMode();
	}
	else if (cmdhead.compare("exit") == 0)
	{
		exit(0);
	}
	else if (cmdhead.compare("quit") == 0)
	{
		exit(0);
	}
	else
	{
		cout << "Unknown command" << endl;
		InteractiveMode();
	}

}

int main(int argc, char * argv[])
{
	InteractiveMode();

	return 0;
}
