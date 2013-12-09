/*
 * This program calculates the number of combinations of making a number num
 * from {1 2 .. choice} by addition.
 * For example, to calculate the possible combinations of cards used from 15 to
 * 21, we can let num be 6 and choice be 10. Thus the result is 11.
 */

#include <stdio.h>

int comb(int num, int choice)
{
	int sum = 0;

	if ((num == 1) || (num == 0) || (choice == 1))
	{
		return 1;
	}
	else
	{
		for (int i=0; i<num; i++)
		{
			if ((num-i) > choice)
				continue;

			sum += comb(i, num-i);
		}
		return sum;
	}
}

int main(int argc, char *argv[])
{
	int sum;
	if (argc >= 3)
	{
		sum = comb(atoi(argv[1]), atoi(argv[2]));
		printf("%d\n", sum);
	}
}
