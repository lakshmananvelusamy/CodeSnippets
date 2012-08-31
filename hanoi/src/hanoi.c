/*
 ============================================================================
 Name        : hanoi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void hanoi(char src, char inter, char desti, int n)
{
	if (n == 0)
		return;
	if (n == 1)
	{
		printf("Move from %c to %c\n", src, desti);
		return;
	}
	printf("Move from %c to %c\n", src, inter);
	hanoi(src, desti, inter, n-1);
	printf("Move from %c to %c\n", src, desti);
	hanoi(inter, src, desti, n-2);
}

int main(void) {
	int n;
	printf("Enter no of disks : ");
	fflush(stdout);
	scanf("%d", &n);
	hanoi('A', 'B', 'C', n);
}
