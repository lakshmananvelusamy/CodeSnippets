/*
 ============================================================================
 Name        : find_median.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int kth_smallest_element(int *a, int n, int k)
{
	int i;
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j <= k; j++)
		{
			if (a[i] > a[j])
			{
				int t;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	return a[k];
}

int median(int *a, int *b, int n1, int n2)
{
	int p1, p2, v1, v2;
	p1 = n1/2;
	p2 = n2/2;
	v1=  kth_smallest_element(a, n, p1);
	v2 =  kth_smallest_element(b, n, p2);
	if (v1 > v2)
	{
		median(a+p1, b, p1, p2);
	}
	else
	{
		median(a, b+p2, p1, p2);
	}
}
int main(void) {
	int n, n1, n2;
	int a1[1024], a2[1024];

	printf("Enter the no of elements : ");
	fflush(stdout);
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter List 1 Element %d :");
		fflush(stdout);
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("Enter List 2 Element %d :");
		fflush(stdout);
		scanf("%d", &a[i]);
	}
	printf("Median element = %d \n", median(a, b, n));
	fflush(stdout);
}
