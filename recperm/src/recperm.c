/*
 ============================================================================
 Name        : recperm.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

# include <stdio.h>
# include <conio.h>

/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
   int j;
   static int pcount = 0;
   if (i == n)
   {
	   int left, right;
	   printf("%s ", a);
	   left  = 0;
	   right = n;
	   while ( left <= right && a[left] == a[right])
	   {
		   left++, right--;
	   }
	   if ( left > right)
	   {
		   pcount++;
		   printf(" PALINDROME count = %d", pcount);
	   }
	   printf("\n");
   }
   else
   {
        for (j = i; j <= n; j++)
       {
        	/*if (a[i] == a[j] && i != j)
        		continue;*/
         		swap((a+i), (a+j));
        		permute(a, i+1, n);
        		swap((a+i), (a+j)); //backtrack
       }
   }
}

/* Driver program to test above functions */
int main()
{
   char a[1024];
   printf("Enter String : ");
   fflush(stdout);
   scanf("%s", a);
   permute(a, 0, strlen(a)-1);
   return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

void swap(char *s, int a, int b)
{
	char t;
	t = s[a];
	s[a] = s[b];
	s[b] = t;
}
void permutation(char *s, int len, int k)
{
	int i, j;
	printf("%s\n", s);
	fflush(stdout);

	for (i = k+1; i < len; i++)
	{
		char t[1024];
		strcpy(t, s);
		swap(t, k, i);
		permutation(t, len, i);
	}

}
int main(void) {
	int s[1024];
	int n, i;
	printf("Enter the string : ");
	fflush(stdout);
	scanf("%s", s);
	n = strlen(s);

	for(i = 0; i< n; i++)
	{
		permutation(s, n, i);
	}

	return EXIT_SUCCESS;
}*/
