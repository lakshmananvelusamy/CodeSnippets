#include<stdio.h>
#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
	char s[1024], orig[1024], orig1[1024];
	int i;
	int n, count = 0, pcount = 0, swaps = 0, sc = 0;
	cin>>s;
	n = strlen(s);
	strcpy(orig, s);
	strcpy(orig1, s);
/*	sort(s, s+n);
	for(i = 0; i < n; i++)
	{
		if (s[i] != orig[i])
		{
			sc++;
		}
	}
	swaps += sc!= 0 ? sc - 1: 0;
	
	
	strcpy(orig, s);
*/
	while (prev_permutation(s, s+n))
	{
	   	int left, right;
		count++;
		cout<<s<<endl;
	   	left  = 0;
	   	right = n - 1;
		sc = 0;
	   while ( left <= right && s[left] == s[right])
	   {
		   left++, right--;
	   }
	   if ( left > right)
	   {
		   pcount++;
	   }
	        for(i = 0; i < n; i++)
        {
                if (s[i] != orig[i])
                {
                        sc++;
                }
        }
        swaps += sc!= 0 ? sc - 1: 0;
	strcpy(orig, s);

	}
	strcpy(s, orig1);
	strcpy(orig, orig1);
	while (next_permutation(s, s+n))
	{
	   	int left, right;
		count++;
		cout<<s<<endl;
	   	left  = 0;
	   	right = n - 1;
		sc = 0;
	   while ( left <= right && s[left] == s[right])
	   {
		   left++, right--;
	   }
	   if ( left > right)
	   {
		   pcount++;
	   }
	        for(i = 0; i < n; i++)
        {
                if (s[i] != orig[i])
                {
                        sc++;
                }
        }
        swaps += sc!= 0 ? sc - 1: 0;
	strcpy(orig, s);

	}
	cout<<"PALINDROME COUNT = "<<pcount<<endl;
	cout<<"TOTAL COUNT = "<<count<<endl;
	cout<<"SWAP COUNT = "<<swaps<<endl;
}
