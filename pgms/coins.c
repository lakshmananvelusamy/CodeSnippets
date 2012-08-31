#include<stdio.h>

main()
{
	int *A, n, *C, i, j, T, **K;

	printf("Enter the no of coins : ");
	scanf("%d", &n);

	A = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		printf("Enter the value %d : ", i+1);
		scanf("%d", &A[i]);
	}
	
	printf("Enter the Target Amount : ");
	scanf("%d", &T);
	
	C = (int *)malloc(sizeof(int) * (T + 1));
	K = (int *)malloc(sizeof(int) * (T + 1));
	
	for (i = 0; i < n; i++)
	{
		K[i] = (int *)malloc(sizeof(int) * (T + 1));
	}
	for (i = 0; i < n; i++)
	{
		for(j = 0; j <= T; j++)
		{
			K[i][j] = 0;
		}
	}

	C[0] = 1;
	K[0][A[0]] = 1;
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= T; j++)
		{
			if (j < A[i]) K[i][j] = K[i-1][j];
			else if (j == A[i] && (j > A[i] && K[i - 1][j - A[i]]))
			{
				K[i][j] = K[i-1][j] + 1;
			} 
		}
	}
	for (i = 1; i <= T; i++)
	{
		C[i] = 0;
		for (j = 0; j < n; j++)
		{
			if (A[j] > i)
			{
				break;
			}
			else if(C[i-A[j]] != 0)
			{
				C[i] = C[i] + C[i - A[j]] + 1 - K[n-1][i];
			}
		}
	}
	printf("Total no of ways = %d\n", C[T]);
}
