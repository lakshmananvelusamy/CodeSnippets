#include<stdio.h>
#include<string.h>

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void permut(char *s, int i)
{
	static int n = 0;
	int j;
	if (n == 0)
	{
		n = strlen(s);
	}
	if (strlen(s+i) == 0)
	{
		printf("%s\n", s);
		return;
	}
	for (j = i; j < n; j++)
	{
		swap(s + i, s + j);
		permut(s, i+1);
		swap(s + j, s + i);
	}
}

void combi(char *s, char *s1)
{
	char t[100] = {0};
	if (strlen(s) == 0)
	{
		printf("%s\n", s1);
		return;
	}
	strcpy(t, s1);
	combi(s+1, t);
	int n = strlen(t);
	t[n] = s[0]; t[n+1] = '\0';
	combi(s+1, t);
}
	
main()
{
	char s[100], s1[100];
	printf("Enter the string : ");
	scanf("%s", s);
	strcpy(s1, s);
	permut(s, 0);
	combi(s1, "");
}
