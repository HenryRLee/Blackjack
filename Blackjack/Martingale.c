/*
 * Martingale
 *
 * Player double his bet after every loss so that the first win would recover
 * all previous losses plus win a profit equal to the original stake.
 *
 * Consider p as the probability of winning. If casino has no maximum bet limit,
 * the expectation of player will be p. If casino has a maximum limit, the
 * expectation will be (1 - (1-p)^n * 2^n).
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	long long times = 1000*1000;
	long long budget = times;
	long long bet = 1;
	int maxbet = 50;
	long long i;

	srand(time(NULL));

	for (i=0; i<times; i++)
	{
		if ((rand() % 10000) < 6666)
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
				printf("Bankrupt! Round %lld, bet %lld\n", i, bet);
				break;
			}

			budget -= bet;
			bet = bet * 2;

			if (bet > maxbet)
			{
//				printf("Overflow max bet\n");
				bet = 1;
			}
		}
	}

	printf("Budget %lld\n", budget);

	
	return 0;
}
