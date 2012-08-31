#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main () {
	long long n, k;
	unsigned long long count = 0;
	long long *a;
	cin>>n>>k;
	a = new long long[n];
	for(long long i =0; i < n; i++)
	{
		cin>>a[i];
	}
	vector<long long> myvector (a, a+n);
	vector<long long>::iterator it;
	sort (myvector.begin(), myvector.end());

	it = myvector.begin();
	for(long long i = 0; i<n-1; i++)
	{
		long long start, end, middle;

		start = i+1;
		end = n-1;

		while (start <= end)
		{
			long long t;
			middle = (end + start)/2;
			t = it[middle] - it[i];
			if (t == k)
			{
				count++;
				for(long long l=middle-1; l > i; l--)
				{
					t = it[l] - it[i];
					if(t == k)
					{
						count++;
					}
					else
					{
						break;
					}
				}
				for(long long l=middle+1; l <= end; l++)
				{
					t = it[l] - it[i];
					if(t == k)
					{
						count++;
					}
					else
					{
						break;
					}
				}
				break;
			}
			else if (t < k)
			{
				start = middle+1;
			}
			else
			{
				end = middle - 1;
			}
		}
	}
	cout<<count<<endl;
	fflush(stdout);
}

