/*
 ============================================================================
 Name        : k-shift.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n, a[1024], t,i, k;
	printf("Enter n : ");
	fflush(stdout);
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter the element %d : ", i+1);
		fflush(stdout);
		scanf("%d", &a[i]);
	}

	printf("Enter k : ");
	fflush(stdout);
	scanf("%d", &k);

	k = n - k;
	i = 0; t = a[i];
	do
	{
		i = (i+k)%n;
		a[0] = a[i];
		a[i] = t;
		t = a[0];
	}while(i != 0);

	for(i = 0; i < n; i++)
	{
		printf("%d,", a[i]);
		fflush(stdout);
	}

	return EXIT_SUCCESS;
}
