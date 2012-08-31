#include<iostream>
using namespace std;

int main()
{
	int t, *a, *b, count;
	int i, j;
	cin>>t;

	a = new int[t];
	b = new int[t];

	for(i = 0; i<t; i++)
	{
		cin>>a[i]>>b[i];
	}
	
	for(i = 0; i<t; i++)
	{
		count = 0;
		for(j = a[i]; j <=b[i]; j++)
		{
			int x = j;
			while(x) { count++; x = x & (x-1);}
		}
		cout<<count<<endl;
	}
}

