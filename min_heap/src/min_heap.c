/*
 ============================================================================
 Name        : min_heap.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void place_element_down(int *a, int i, int n)
{
	if (i * 2 > n)
	{
		return;
	}
	int j;
	j = a[i * 2] > a[i * 2 + 1] ? i * 2 : i * 2 + 1;
	if (a[i] > a[j])
	{
		int temp;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		place_element_down(a, j, n);
	}
}
void place_element_up(int *a, int i)
{
	if (i == 1)
	{
		return;
	}

	if (a[i] < a[i/2])
	{
		int temp;
		temp = a[i];
		a[i] = a[i/2];
		a[i/2] = temp;
		place_element_up(a, i/2);
	}
}

void construct_min_heap(int *a, int n)
{
	int i;
	for (i = 2; i <= n; i++)
	{
		place_element_up(a, i);
	}
}

int insert_min_heap(int *a, int n, int e)
{

}
void change_i(int *a, int j, int a1, int n)
{
	if (a[j] == a1)
	{
		return;
	}
	else if (a[j] > a1)
	{
		a[j] = a1;
		place_element_up(a, j);
	}
	else
	{
		a[j] = a1;
		place_element_down(a, j, n);
	}
}

int main(void) {
	int n;
	int i, j;
	int a[1024], a1;

	printf("Enter the number of elements : ");
	fflush(stdout);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		printf("Enter element %d : ", i);
		fflush(stdout);
		scanf("%d", &a[i]);
	}

	construct_min_heap(a, n);
	for (i = 1; i <= n; i++)
	{
		if (!(i & (i-1)))
			printf("\n");
		printf("%d ", a[i]);
		fflush(stdout);
	}
	printf("Enter the index you want to change : ");
	fflush(stdout);
	scanf("%d", &j);
	printf("Enter the new value for %d : ", j);
	fflush(stdout);
	scanf("%d", &a1);
	change_i(a, j, a1, n);
	for (i = 1; i <= n; i++)
	{
		if (!(i & (i-1)))
			printf("\n");
		printf("%d ", a[i]);
		fflush(stdout);
	}
}
