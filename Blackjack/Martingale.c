#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int times = 100;
	long long budget = 1000;
	long long bid = 1;
	int maxbid = 50;
	int i;

	srand(time(NULL));

	for (i=0; i<times; i++)
	{
		if ((rand() % 2) == 0)
		{
			budget += bid;
			bid = 1;
		}
		else
		{
			if ((bid > budget) || (bid > maxbid))
			{
				printf("Bankrupt! Round %d, bid %lld\n", i, bid);
				break;
			}
			budget -= bid;
			bid = bid * 2;
		}
	}

	printf("Budget %lld\n", budget);

	
	return 0;
}
