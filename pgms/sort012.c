#include<stdio.h>

main()
{
	int n;
	int a[100], i;
	int lptr, aptr, rptr;

	printf("Enter N : ");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		printf("Enter a[%d] : ", i+1);
		scanf("%d", &a[i]);
	}
	lptr = 0; rptr = n - 1; aptr = 0;

	while(lptr < rptr)
	{
		while(a[lptr] == 0) lptr++;
		while(a[rptr] == 2) rptr--;
	
		if (a[lptr] == 2)
		{ 
			a[lptr] = a[rptr];
			a[rptr] = 2;
			rptr--;
		}
		if (a[rptr] == 0)
		{ 
			a[rptr] = a[lptr];
			a[lptr] = 0;
			lptr++;
		}
		if (a[lptr] == 1 && a[rptr] == 1) 
		{
			if (aptr <= lptr)
				aptr = lptr + 1;
			while (aptr < rptr)
			{
				if (a[aptr] == 0)
				{
					a[aptr] = 1;
					a[lptr] = 0;
					lptr++;
					aptr++;
					break;
				}
				else if (a[aptr] == 2)
				{
					a[aptr] = 1;
					a[rptr] = 2;
					rptr--;
					aptr++;
					break;
				}
				aptr++;
			}
			if (aptr >= rptr)
				break;
		}
	}	
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
	
