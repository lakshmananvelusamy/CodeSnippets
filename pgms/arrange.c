#include<stdio.h>

main()
{
	int N = 10, n = 5;
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int temp;
	char *mask;
	
	mask = (char *)malloc(N);
	memset(mask, '\0', 10);
	int i, j, i1;
	
	mask[0] = 1;
	mask[N-1] = 1;
	for(i=1; i < N; i++)
	{
		if (mask[i] == 1) continue;
		i1 = i;
		do
		{
			if (i1 < n)
				j = 2 * i1;
			else 
				j = (i1 - n) * 2 + 1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;	
			i1 = j;
			mask[i1] = 1;
		}while(i != j);
		mask[i] = 1;
	}
	for (i = 0; i < N; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
	return;
}
