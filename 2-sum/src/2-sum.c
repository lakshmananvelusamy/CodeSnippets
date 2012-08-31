

#include <stdio.h>
#include <stdlib.h>

void find_rank(int *a, int low, int high)
{
	int med, i, j;

	med = (high + low)/2;
	if(low == med )
	{
		return ;
	}


	find_rank(a,r,p, low, med);
	find_rank(a,r,p, med, high);

	for (i = low, j = med; i < med && j < n; )
	{
		if (a[i] < a[j])
		{
			int t;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i ++;
		}
		else
		{
			int t;
			t = a[j];

			r[j] = rank;
			*link = j;
			link = &p[j];
			j = p[j];
		}
	}

	while (i != -1)
	{
		r[i] = rank;
		rank++;
		*link = i;
		link = &p[i];
		i = p[i];
	}
	while (j != -1)
	{
		r[j] = rank;
		rank++;
		*link = j;
		link = &p[j];
		j = p[j];
	}
	*link = -1;
	return headl;
}


int main() {
	int i, a[1024], r[1024], p[1024], n;
	printf("Enter the no of elements : ");
	fflush(stdout);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter element %d : ", i+1);
		fflush(stdout);
		scanf("%d", &a[i]);
	}

	find_rank(a,r, p, 0, n);
	printf("\nOUTPUT : \n{ ");
	fflush(stdout);
	for (i = 0; i < n; i++)
		{
			printf("[%d, %d], ", a[i], r[i]);
			fflush(stdout);
		}
	printf("\b\b }\n");
	fflush(stdout);
	return 0;
}

