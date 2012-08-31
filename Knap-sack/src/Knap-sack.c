/*
 ============================================================================
 Name        : Knap-sack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
struct result
{
	int profit;
	char pick[1024];
};

struct result knap_sack(int *a, int *p, int n, int w)
{
	struct result r={0,{-1}};
	struct result r1, r2;

	if (n < 0 || w <= 0)
		return r;
	if (a[n] <= w)
	{
		r1 = knap_sack(a, p, n-1, w);
		r2 = knap_sack(a, p, n-1, w-a[n]);
		r2.profit += p[n];
		if (r1.profit > r2.profit)
		{
			r= r1;
		}
		else
		{
			r = r2;
			r.pick[n] = 1;
		}
		return r;
	}
	else
	{
		return knap_sack(a, p, n-1, w);
	}
}
int main(void) {
	int n, a[100], p[100], i, w;
	struct result r;

	printf("Enter the no of elements : ");
	fflush(stdout);
	scanf("%d", &n);

	printf("Enter the Capacity : ");
	fflush(stdout);
	scanf("%d", &w);

	for(i = 0; i < n; i++)
	{
		printf("Enter number %d : ", i+1);
		fflush(stdout);
		scanf("%d", &a[i]);
		printf("Enter Profit : ");
		fflush(stdout);
		scanf("%d", &p[i]);
	}

	r = knap_sack(a, p, n-1, w);
	for (i = 0; i < n; i++)
	{
		if (r.pick[i] != -1)
		{
			printf("%d ", i+1);
		}
	}
	printf("\nTotal profit =  %d\n", r.profit);



}
