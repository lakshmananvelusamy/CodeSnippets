#include <iostream>

int main()
{
	int t;
	int *n, **a;
	register int i, j;

	cin>>t;
	n = new int[t];
	a = new int*[n];
	for(i = 0; i < n; i++)
	{
	cin>>n[i];
	a[i] = new int[n[i];
	for(j = 0; j < n[i]; j++)
	{
		cin>>a[i][j];
	}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 1; j <= n-1; j++)
		{
				
