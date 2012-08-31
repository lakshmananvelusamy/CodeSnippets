/*
 ============================================================================
 Name        : 3-gift.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int binary(int *a, int low, int high, int e)
{
	int med;
	med = (low+high)/2;
	if (low > high)
	{
		return -1*med;
	}
	if (a[med] == e) return med;
	if(a[med] > e) binary(a, low, med-1, e);
	else binary(a, med+1, high, e);
}

int main(void) {
	int n;
	int a[1024];
	int i, j, k, d;
	int left, right;

	printf("Enter N : ");
	fflush(stdout);
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf ("Enter element %d : ", i+1);
		fflush(stdout);
		scanf("%d", &a[i]);
	}


	for(i=0; i< n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[j] < a[i])
			{
				int t;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	printf("SORTED LIST \n\n\n");
	for(i = 0; i < n; i++)
	{
		printf ("%d ", a[i]);
		fflush(stdout);
	}

	printf("Enter the sum : ");
	fflush(stdout);
	scanf("%d", &d);

	left = 0;
	right = n;
	while (left < right)
	{
		if (a[left]+a[right] >= d) {right --;}
		else
		{
			int c;
			c = d - a[left] - a[right];
			i = binary(a, 0, n, c);
			if(i >= 0)
			{
				if (i == left)
				{
					right--;
				}
				else if (i == right)
				{
					left++;
				}
				else
				{
					printf("FOUND  !!!! %d + %d + %d = %d\n", a[left], a[right], a[i], a[left]+ a[right]+ a[i]);
					fflush(stdout);
					return;
				}
			}
			else if (-1*i < left) {right--;}
			else left++;
		}
	}

	printf("FAIL\n\n");
	fflush(stdout);

}
