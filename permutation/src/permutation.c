/*
 ============================================================================
 Name        : permutation.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int next_permute(char *s)
{
        int i, j, t, n;
        int t1[1024], t2[1024];
        int left, right, k;
        n = strlen(s);
        i = i-1;
    j = i-1;
    for(i= n-1; i>=0; i--)
    {
    	if (s[i] >s[i-1])
    	{
    		j = n-1;
    		while (s[j] < s[i-1]) j--;
    		t = s[i-1];
    		s[i-1] = s[j];

    		for(k =0; k < j-i; k++)
    		{
    			t1[k] = s[j - k -1];
    		}
    		for(k = 0; k < n-1-j; k++)
    		{
    			t2[k] = s[n-1-k];
    		}

    		for(k = 0; k < n-1-j; k++)
    		{
    			s[k+i] = t2[k];
    		}
    		s[k+i] = t;

    		for(k=0; k < j-i; k++)
    		{
    			s[k+i+n-j] = t1[k];
    		}
    		return 0;
    	}
    }
    return -1;

}

int main()
{
      char s[1024] = "1234";
      printf("Enter the number : ");
      int count = 0;
      int i, j, n;
      fflush(stdout);
      gets(s);
      n = strlen(s);
      for(i=0; i<n; i++)
      {
    	  for(j = i+1; j<n; j++)
    	  {
    		  if(s[i] > s[j])
    		  {
    			  char t;
    			  t = s[i];
    			  s[i] = s[j];
    			  s[j] = t;
    		  }
    	  }
      }
      printf("%s\n", s);
     while (next_permute(s) == 0)
      {
 //   	  next_permute(s);
           printf("%s\n", s);
           count++;
           fflush(stdout);
      }
      printf("Total = %d\n", count);
      return 0;
}
