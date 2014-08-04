#include <iostream>
#include <string>
#include "AdvancedCalculator.h"
#include "SimpleFastCalculator.h"
#include "AdvancedFastCalculator.h"

using namespace std;

bool bShowDetail;
bool bShowDelta;
UsedCard usedcard;
int iAction;

enum ActionAllowed
{
	DOUBLE=1, SPLIT=2,
};

void EvMain(string arg)
{
	ProbabilityCalculator * cal = new AdvancedCalculator;
//	ProbabilityCalculator * cal = new SimpleFastCalculator;
//	ProbabilityCalculator * cal = new AdvancedFastCalculator;
	UsedCard current = usedcard;
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

		if (atoi(sDScore.c_str()) <= 11)
			current.GetOneCard(atoi(sDScore.c_str()));
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
			bool bPSoft = false;
			bool bDSoft = false;

			sPSoft = rest.substr(0, delim);
			if (atoi(sPSoft.c_str()) == 1)
			{
				bPSoft = true;
				current.GetOneCard(11);
			}
			else
			{
				bPSoft = false;
			}
			rest = rest.substr(delim+1);

			sDSoft = rest.substr(0, delim);
			if (atoi(sDSoft.c_str()) == 1)
			{
				bDSoft = true;
				current.GetOneCard(11);
			}
			else
			{
				bDSoft = false;
			}

			if (bShowDelta)
			{
				cout << "Delta of this case is not supported" << endl;
			}
			else if (bShowDetail)
			{
				cal->ShowProbSetByNextCard(atoi(sPScore.c_str()), 
						bPSoft, atoi(sDScore.c_str()), 
						bDSoft, iAction, &current);
			}
			else
			{
				cal->ShowProbSetByAction(atoi(sPScore.c_str()), 
						bPSoft, atoi(sDScore.c_str()), 
						bDSoft, iAction, &current);
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
		if (bShowDelta)
		{
			int iFirst;
			int iSecond;
			if ((sPScore.compare("16")==0) && (sDScore.compare("10")==0))
				cal->ShowDeltaOfEachTakenCard(atoi(sPScore.c_str()), 
						false, atoi(sDScore.c_str()), false, 1, 2, &current);
			else if ((sPScore.compare("14")==0) && (sDScore.compare("10")==0))
				cal->ShowDeltaOfEachTakenCard(atoi(sPScore.c_str()), 
						false, atoi(sDScore.c_str()), false, 1, 5, &current);
			else if ((sPScore.compare("16")==0) && (sDScore.compare("9")==0))
				cal->ShowDeltaOfEachTakenCard(atoi(sPScore.c_str()), 
						false, atoi(sDScore.c_str()), false, 1, 5, &current);
			else
				cout << "Delta of this case is not supported" << endl;
		}
		else if (bShowDetail)
		{
			cal->ShowProbSetByNextCard(atoi(sPScore.c_str()), false, 
					atoi(sDScore.c_str()), false, iAction, &current);
		}
		else
		{
			cal->ShowProbSetByAction(atoi(sPScore.c_str()), false, 
					atoi(sDScore.c_str()), false, iAction, &current);
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
	else if (cmdhead.compare("delta") == 0)
	{
		if (cmdarg.compare("off") == 0)
		{
			bShowDelta = false;
			cout << "Delta off" << endl;
		}
		else
		{
			bShowDelta = true;
			cout << "Delta on" << endl;
		}
		InteractiveMode();
	}
	else if (cmdhead.compare("take") == 0)
	{
		PushCards(cmdarg);
		InteractiveMode();
	}
	else if (cmdhead.compare("clear") == 0)
	{
		usedcard.Clear();
		InteractiveMode();
	}
	else if (cmdhead.compare("split") == 0)
	{
		if (cmdarg.compare("off") == 0)
		{
			iAction &= ~SPLIT;
			cout << "Split off" << endl;
		}
		else
		{
			iAction |= SPLIT;
			cout << "Split on" << endl;
		}
		InteractiveMode();
	}
	else if (cmdhead.compare("double") == 0)
	{
		if (cmdarg.compare("off") == 0)
		{
			iAction &= ~DOUBLE;
			cout << "Double off" << endl;
		}
		else
		{
			iAction |= DOUBLE;
			cout << "Double on" << endl;
		}
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
	if (argc == 1)
	{
		InteractiveMode();
	}
	else
	{
		string args;
		for (int i=1; i<argc; i++)
		{
			if (argv[i][0] == '-')
			{
				if (strlen(argv[i]) > 1)
				{
					switch (argv[i][1])
					{
					case 'd':
						iAction |= DOUBLE;
						break;
					case 's':
						iAction |= SPLIT;
						break;
					default:
						break;
					}
				}
				else
				{
					cout << "./EV [-d] [-s] <Player Score> <Dealer Score> "
						"[<Player is Soft> <Dealer is Soft>]" << endl;
				}
			}
			else
			{
				args.append(argv[i]);

				if (i != argc - 1)
					args.append(" ");
			}
		}
		EvMain(args);
	}

	return 0;
}
