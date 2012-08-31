/*
 ============================================================================
 Name        : Hello.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * looser.c
 *
 *  Created on: Sep 5, 2011
 *      Author: Lakshmanan Velusamy
 *      Objective : Looser tree data structure construction (using arrays)
 */

#include<stdio.h>
#include<stdlib.h>

void construct_looser_tree(int *, int );
void construct_looser_tree(int *, int );

int main()
{
	int n, *a;
	int i = 0, level;

	printf("Enter the number of elements : ");
	fflush(stdout);
	scanf("%d", &n);

	a = (int *)calloc(2 * n, sizeof(int));

	/* Get the inputs */
	for (i=0; i<n; i++)
	{
		printf("Enter Value %d", i);
		fflush(stdout);
		scanf("%d", &a[n+i]);
	}

	construct_looser_tree(a, n);

	printf("TREE IN ARRAY REPRESENTATION\n");
	for (level = 1, i = 0; i < 2 * n; i++)
	{
		if ( !(i & i-1) )
		{
			printf("**********\nLEVEL %d:\n**********\n", level++);
		}
		printf("A[%d] %d\n", i, a[i]);
		fflush(stdout);
	}
	return 0;
}

void construct_looser_tree(int *a, int n)
{
	int i, condition;
	condition = 2 * n;
	for (i=n; i < condition; i+=2)
	{
		int looser;
		if (a[i] > a[i+1])
		{
			a[i/2] = a[i];
			looser = a[i+1];
		}
		else
		{
			a[i/2] = a[i+1];
			looser = a[i];
		}
		play_and_advance(a, i/4, looser);
	}
}

void play_and_advance(int *a, int i, int x)
{

	if (a[i] == 0)
	{
		a[i] = x;
		if (i == 0)
		{
			printf("The winner is %d", a[0]);
		}
	}

	else
	{
		if (a[i] > x)
		{
			play_and_advance(a, i/2, x);
		}
		else
		{
			int looser;
			looser = a[i];
			a[i] = x;
			play_and_advance(a, i/2, looser);
		}
	}
}
