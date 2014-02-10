/*
 * This program calculates the number of combinations of reaching an integer num
 * by adding integers from the set {1 2 .. choices}.
 * For example, to count the possible combinations of cards used from 16 to
 * 21, we can let num be 5 and choices be 10. The result is 7.
 * All combinations in this example are listed below.
 *    A 2 3 4 5 6 7 8 9 T
 *    5 0 0 0 0 0 0 0 0 0
 *    3 1 0 0 0 0 0 0 0 0
 *    1 2 0 0 0 0 0 0 0 0
 *    2 0 1 0 0 0 0 0 0 0
 *    0 1 1 0 0 0 0 0 0 0
 *    1 0 0 1 0 0 0 0 0 0
 *    0 0 0 0 1 0 0 0 0 0
 */

#include <stdio.h>

int comb(int num, int choices)
{
	int sum = 0;

	if ((num == 1) || (num == 0) || (choices == 1))
	{
		return 1;
	}
	else
	{
		for (int i=0; i<num; i++)
		{
			if ((num-i) > choices)
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

	return 0;
}
