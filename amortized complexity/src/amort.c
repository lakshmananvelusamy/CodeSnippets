/*
 ============================================================================
 Name        : amort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

int powerof3(int i)
{
	static int a = 3;
	if (i == a)
	{
		a*=3;
		return TRUE;
	}
	return FALSE;
}

int main()
{
	int i =2;
	double cost = 9.0000;
	long long int total = 1;

	while(i > 0)
	{
		if (!(i & (i-1)))
		{
			total += 2 *i;
		}
		else if (!powerof3(i))
		{
			total += 3 * i;
		}
		else
		{
			total ++;
		}
		cost +=9.000;
		//printf("ACTUAL %lld AMORTIZED = %lf POTENTIAL = %lf\n", total, cost, cost- (double)total );
		if ((cost - total) <= 0)
			printf("FAIL %lf", cost- (double)total);

		i++;
	}
	printf ("SUCCESS, Final potential = %lf, actual cost = %lld \n",  cost- (double)total, total);
	return 0;
}
