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

struct fill
{
	int max, lmax, rmax, sum;
};

int maximum(int x, int y)
{
	if (x > y) return x;
	else return y;
}
struct sum max_sum(int *a, int n, struct fill * f)
{
	struct sum s;
	struct fill f1, f2;
	if (n == 1)
	{
		f->lmax = a[0];
		f->rmax = a[0];
		f->max = a[0];
		f->sum = a[0];

		s.i = n;
		s.j = n;
		s.sum = a[n];
		return s;
	}
	max_sum(a, n/2, &f1);
	max_sum(a+n/2, n/2, &f2);

	f->sum = f1.sum + f2.sum;
	f->lmax = maximum(f1.sum + f2.lmax, f1.lmax);
	f->rmax = maximum(f2.sum + f1.rmax, f2.rmax);
	f->max = maximum(f1.max, maximum(f2.max, f1.rmax + f2.lmax));
	s.sum = f->max;
	return s;
}
int main(void) {
	int n, i;
	int a[1024];
	struct fill f;
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
