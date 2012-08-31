

#include <stdio.h>
#include <stdlib.h>

int find_rank(int *a, int *r, int *p, int low, int high)
{
	int med, headl, headr, *link, rank;
	int i,j;

	med = (high + low)/2;
	if(low == med )
	{
		r[low] = 1;
		p[low] = -1;
		return low;
	}


	headl = find_rank(a,r,p, low, med);
	headr = find_rank(a,r,p, med, high);
	link = &headl;

	for (rank = 1, i = headl, j = headr; i != -1 && j != -1; rank++)
	{
		if (a[i] < a[j])
		{
			r[i] = rank;
			*link = i;
			link = &p[i];
			i = p[i];
		}
		else
		{
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

