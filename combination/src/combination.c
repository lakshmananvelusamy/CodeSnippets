/*
 ============================================================================
 Name        : Knap-sack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

void Combination(char *a, int n, int i, char *s)
{
	char t;
	if (n < 0)
	{
		printf("%s\n", s);
		fflush(stdout);
		return;
	}
	Combination(a,n-1, s);
	t = s[i];
	s[i] = a[n];
	Combination(a, n-1, s);
	s[n] = t;
}
int main(void) {
	char a[1024], s[1024]={0};
	int n;

	printf("Enter the string : ");
	fflush(stdout);
	scanf("%s", a);

	n = strlen(a);
	Combination(a,n-1,s);
}
