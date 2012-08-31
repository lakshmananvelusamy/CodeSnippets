#include<stdio.h>

int fun(int *parr[10])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		parr[i] = i;
	}
}

int main()
{
	int *parr[10]={NULL};
	int i;
	fun(parr);
	for (i = 0; i < 10; i++)
	{
		printf("%x\n", parr[i]);
	}
}
