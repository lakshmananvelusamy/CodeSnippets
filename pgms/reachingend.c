#include<stdio.h>

main()
{
	int n, *a, *p, *c;
	
	int i, j, min, minindex;

	printf("Enter n : ");
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * n);
	p = (int *)malloc(sizeof(int) * n);
	c = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		printf ("Element %d : ", i + 1);
		scanf("%d", &a[i]);
	}
	
	c[0] = 0;
	p[0] = -1;

	for (i = 1; i < n; i++)
	{
		min = 1000000;
		minindex = -1;
		for (j = i-1; j >= 0; j--)
		{
			if (j + a[j] >= i && min > c[j])
			{
				minindex = j;
				min = c[j];
			}
		}
		c[i] = min + 1;
		p[i] = minindex;
	}
	
	printf("No of steps = %d\n", c[n-1]);
	
	printf("PATH: ");
	i = p[n-1];
	while (i >= 0)
	{
		printf("%d <- ", i);
		i = p[i];
	}
	printf("\n");
}
	
				
			
