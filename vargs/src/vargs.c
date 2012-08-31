/*
 ============================================================================
 Name        : vargs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int average(int n, ...)
{
	va_list v;
	int i, sum = 0;
	va_start(v, n);
	for(i = 0; i < n; i++)
	{
		sum += va_arg(v, int);
	}
	printf("Sum = %d Average = %d\n", sum, sum/n);
	va_end(v);

}

int main(void) {

	average(5, 1, 2, 3, 4, 5);
	return EXIT_SUCCESS;
}
