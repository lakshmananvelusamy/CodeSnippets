#include<stdio.h>

main()
{
	int proc = 10;
	if (proc--, 0)
	{
		printf("0 doesn't get evaluated\n");
	}
}
