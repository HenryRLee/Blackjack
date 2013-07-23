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

	return 0;
}
