/*
 ============================================================================
 Name        : merge_sort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *a, int n)
{
	int i, j, *t1, *t2, k = 0;
	int mid;
	if (n == 1)
	{
		return;
	}

	mid = n/2;
	merge_sort(a, mid);
	merge_sort(a+mid, n-mid);

	t1 = (int *)malloc(mid*sizeof(int));
	t2 = (int *)malloc((n-mid)*sizeof(int));

	for(i = 0; i < mid; i++)
	{
		t1[i] = a[i];
	}
	for(i = mid; i < n; i++)
	{
		t2[i-mid] = a[i];
	}

	i = 0; j = mid; k =0;
	while(i < mid || j < n)
	{
		if(t1[i] < t2[j-mid])
		{
			a[k] = t1[i];
			i++;

		}
		else
		{
			a[k] = t2[i];
			j++;
		}
		k++;
	}
	while(i < mid)
	{
		a[k] = t1[i];
		i++;
		k++;
	}
	while(j < n)
	{
		a[k] = t2[j];
		j++;
		k++;
	}
	free(t1);
	free(t2);
}
int main(void) {
	int *a, n, i;

	printf("Enter the no of elements : ");
	fflush(stdout);
	scanf("%d", &n);

	a = (int*)malloc(n * sizeof(int));

	for(i = 0; i < n; i++)
	{
		printf("Enter the %d the element : ", i+1);
		fflush(stdout);
		scanf("%d", &a[i]);
	}

	printf("INPUT : \n");

	for(i = 0; i < n; i++)
	{
		printf(" %d, ", a[i]);
		fflush(stdout);
	}
	merge_sort(a,n);

	printf("OUTPUT : \n");

	for(i = 0; i < n; i++)
	{
		printf(" %d, ", a[i]);
		fflush(stdout);
	}
}
