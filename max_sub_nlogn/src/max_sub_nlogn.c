/*
 ============================================================================
 Name        : max_sub.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct sum
{
	int i,j,sum;
};

int maximum(int x, int y)
{
	if (x > y) return x;
	else return y;
}
struct sum max_sum(int *a, int n, int * f)
{
	struct sum s;
	int f1, f2;
	if (n == 1)
	{
		s.i = n;
		s.j = n;
		s.sum = a[n];
		return s;
	}
	max_sum(a, n/2, &f1);
	max_sum(a+n/2, n/2, &f2);

	return s;
}
int main(void) {
	int n, i;
	int a[1024];
	int f;
	struct sum s;

	printf("Enter N :");
	fflush(stdout);
	scanf("%d", &n);

	for (i =0; i < n; i++)
	{
		printf("Enter element %d : ", i+1);
		fflush(stdout);
		scanf("%d", &a[i]);
	}

	s = max_sum(a, n, &f);
	printf("MAX SUM = %d\n", s.sum);
	/*printf("Maxmium sub-sequence  :\n{ ");
	for (i = s.i; i <= s.j; i++)
	{
		printf("%d ", a[i]);
	}
	printf("}\n"); */
	return 0;
}
