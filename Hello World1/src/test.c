/*
 * test.c
 *
 *  Created on: Sep 7, 2011
 *      Author: Laxman
 */
/*

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
	int i =1;
	double cost = 9.5000;
	int acost=1;
	int total = 0;

	while(i++)
	{
		if (!(i & (i-1)))
		{
			total += 2 *i;
		}
		if (powerof3(i))
		{
			total += 3 * i;
		}
		else
		{
			total ++;
		}
		cost +=9.500;
		if ((cost - total) <= 0)
			printf("FAIL %lf", cost-total);
		else
			printf(" %lf", cost-total);
	}
	return 0;
}
*/
