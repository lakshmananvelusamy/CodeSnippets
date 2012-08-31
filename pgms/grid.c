#include<stdio.h>

main()
{
	int m, n, i, j, **a, a1, a2;
	printf("Enter m : ");
	scanf("%d", &m);
	printf("Enter n : ");
	scanf("%d", &n);

	a = (int *)malloc(sizeof(int *) * (m + 1));

	for(i = 0; i <= m; i++)
	{
		a[i] = (int *)malloc(sizeof(int) * (n + 1));
	}
	a[0][0] = 0;

	for(i = 0; i <=  m; i++)
	{
		a[i][0] = 1;
	}

	for(i = 0; i <= n; i++)
	{
		a[0][i] = 1;
	}

	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}
	for(i = 0; i <= m; i++)
	{
		for(j = 0; j <= n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", a[m][n]);
}
