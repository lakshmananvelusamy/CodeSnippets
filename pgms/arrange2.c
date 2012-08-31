#include<stdio.h>

main()
{
//	int N = 15;
//	int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	int N;
	int *a;
	int i, j, i1;

	printf("Enter the no of elements : ");
	scanf("%d", &N);
	a = (int *)malloc(sizeof(int) * 3 * N);

	for(i = 0; i < 3 * N; i++)
	{
		char c;
		if ( i < N)
			c = 'a';
		else if ( i < 2 * N)
			c = 'b';
		else
			c = 'c';
		printf("Enter %c[%d] : ", c, i + 1);
		scanf("%d", & a[i]);
	}
	N *= 3;
	
	for (i = 0; i < N; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
	
	a[0] *= -1;
	a[N-1] *= -1;
	for(i=1; i < N; i++)
	{
		if (a[i] <  0) continue;
		i1 = i;
		do
		{
			if (i1 < N/3)
				j = 3 * i1;
			else   if (i1 < 2 * N / 3)
				j = (i1 * 3 - N) + 1;
			else
				j = (i1 * 3 - 2 * N) + 2;
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
