//============================================================================
// Name        : k-difference.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main () {
	long long n, k;
	unsigned long long count = 0;
	long long *a;
	fflush(stdin);
	cin>>n>>k;
	a = new long long[n];
	for(int i =0; i < n; i++)
	{
		fflush(stdin);
		cin>>a[i];
	}
	vector<int> myvector (a, a+n);
	vector<int>::iterator it;
	sort (myvector.begin(), myvector.end());

	for(int i = 0; i<n-1; i++)
	{
		int start, end, middle;

		start = i+1;

		end = n-1;
		while (start < end)
		{
			int t;
			middle = (end - start)/2;
			t = a[middle] - a[i];
			if (t == k)
			{
				count++;
				for(int l=middle-1; l > i; l--)
				{
					t = a[l] - a[i];
					if(t == k)
					{
						count++;
					}
					else
					{
						break;
					}
				}
				for(int l=middle+1; l < end; l++)
				{
					t = a[l] - a[i];
					if(t == k)
					{
						count++;
					}
					else
					{
						break;
					}
				}
			}
			else if (t <= k)
			{
				start = middle+1;
			}
			else
			{
				end = middle - 1;
			}
		}
	}
	cout<<"Count = "<<count<<endl;
	fflush(stdout);
}




