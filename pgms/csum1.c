#include <iostream>
using namespace std;
int main()
{
	register int t, *n, mod;
	register long long i, j, k, z;
	unsigned long long *m;
	register long long **a, **b;
	cin>>t;
	a = new long long*[t];
	b = new long long*[t];
	n = new int[t];
	m = new long long[t];
for(z = 1; z <= t; z++)
{
	cin>>n[z]>>m[t];
	a[z] = new long long[n+2];
	b[z] = new long long[n+2];
}
for(z = 1; z <= t; z++)
{
	mod = n+1;
	for(i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	a[0] = a[n];
	a[n+1] = a[1];
	
	for (k = 1; k <= n; k++)
	{
		memcpy(b, a, (n+2) * sizeof(long long));
		for(i = 1; i <= m; i++)
		{
			j = (k+i-1) % mod;
			b[j] = b[j]+b[j-1]+b[j+1];
			if(j == 1) b[mod] = b[1];
			else if (j == n) b[0] = b[n];
		}
		for(j = 1; j <= n; j++)
			cout<<b[j]%1000000007<<" ";
		cout<<endl;
	}
	delete []a;
	delete []b;
}
	return 0;
}
