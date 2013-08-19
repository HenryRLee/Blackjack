#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int times = 100;
	long long budget = 1000;
	long long bet = 1;
	int maxbet = 50;
	int i;

	srand(time(NULL));

	for (i=0; i<times; i++)
	{
		if ((rand() % 2) == 0)
		{
			budget += bet;
			bet = 1;
		}
		else
		{
			if ((bet > budget) || (bet > maxbet))
			{
				printf("Bankrupt! Round %d, bet %lld\n", i, bet);
				break;
			}
			budget -= bet;
			bet = bet * 2;
		}
	}

	printf("Budget %lld\n", budget);

	
	return 0;
}
