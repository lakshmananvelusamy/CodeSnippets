#include<stdio.h>

main()
{
	int N = 10;
	int a[]={1,2,3,4,5,6,7,8,9,10};
	
	int i, j, i1;
	
	a[0] *= -1;
	a[N-1] *= -1;
	for(i=1; i < N; i++)
	{
		if (a[i] <  0) continue;
		i1 = i;
		do
		{
			if (i1 < N/2)
				j = 2 * i1;
			else 
				j = (i1 * 2 - N) + 1;
			if (i != j) {
				a[i] = a[j]+a[i];
				a[j] = a[i]-a[j];
				a[i] = a[i]-a[j];
			}
			i1 = j;
			a[i1] *= -1;
		}while(i != j);
		a[i] *= -1;
	}
	for (i = 0; i < N; i++)
	{
		if (a[i] < 0) a[i] *= -1;
		printf("%d  ", a[i]);
	}
	printf("\n");
	return;
}
