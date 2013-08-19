#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int times = 100*1000;
	long long budget = 1000;
	long long bet = 1;
	int maxbet = 50;
	int i;

	srand(time(NULL));

	for (i=0; i<times; i++)
	{
		if ((rand() % 1000) < 505)
		{
			/* Win */
			budget += bet;
			bet = 1;
		}
		else
		{
			/* Lose */
			if (bet > budget)
			{
				printf("Bankrupt! Round %d, bet %lld\n", i, bet);
				break;
			}

			budget -= bet;
			bet = bet * 2;

			if (bet > maxbet)
			{
				printf("Overflow max bet\n");
				bet = 1;
			}
		}
	}

	printf("Budget %lld\n", budget);

	
	return 0;
}
