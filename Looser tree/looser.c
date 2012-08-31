/*
 * looser.c
 *
 *  Created on: Sep 5, 2011
 *      Author: Laxman
 */

main(int argc, char *argv[])
{
	int n, *a;
	int i = 0;

	/* Validate the command line arguments */
	if (argc != 1)
	{
		printf("USAGE : <looser n>\n");
		return -1;
	}

	/* Get the inputs */
	n = atoi(argv[1]);
	a = (int *)malloc(2 * n * sizeof(int));
	memset(a, 0, 2 * n * sizeof(int));

	for (i=1; i<=n; i++)
	{
		printf("Enter Value %d", i);
		scanf("%d", a[n+i]);
	}

	//construct_looser_tree(a, n);
	return 0;
}

void construct_looser_tree(int *a, int n)
{
	int i, condition;
	condition = 2 * n;
	for (i=n; i < condition; i++)
	{
		play_and_advance(a, i);
	}
}

void play_and_advance(int *a, int i)
{
	if (i == 0)
	{
		printf("The winner is %d", a[0]);
		return ;
	}

	if (i & 1)
	{
		if (a[i] > a[i-1])
		{
			if (a[i/2] == 0)
			{
				a[i/2] = a[i];
			}
			play_and_advance(a, i/4);
		}
	}
}
