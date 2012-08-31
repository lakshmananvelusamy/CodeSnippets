#include<iostream>

using namespace std;
/*

void find_paths(struct A *p, int n)
{
	vector<int> vec1 (p->x, p->x+n);
	vector<int> vec2 (p->y, p->y+n);
	vector<int>::iterator it;
	sort(myvector.begin(), myvector.end());
	
  
	
}
*/

int main()
{
	int t, i, j;
	int *n;
	struct P
	{
		int a, b;
	};
	struct A
	{
		struct P *k;
	}*p;
	
	cin>>t;
	n = new int[t];
	p = new A[t];
	for (i = 0; i < t; i++)
	{
		cin>>n[i];
		p[i].k = new P[n[i]];
		for(j = 0; j < n[i]-1; j++)
		{
			cin>>p[i].k[j].a>>p[i].k[j].b;
		}
	}

	for (i = 0; i < t; i++)
	{
		// find leaf/source/sink nodes
		int *ncount, lcount = 0;
		ncount = new int[n[i]];
		for (j = 0; j < n[i]; j++)
		{
			ncount[j] = 0;
		}
		
		for (j = 0; j < n[i]-1; j++)
		{
			ncount[p[i].k[j].a]++;
			ncount[p[i].k[j].b]++;
		}
		for (j = 0; j < n[i]; j++)
		{
			if(ncount[j] == 1)
			{
				cout<<j<<" ";
			}
		}
		/*		if (j == p[i].k[j].a)
		for (j = 0; j < n[i]-1; j++)
		{
			if
			if(p[i].k[j].a > p[i].k[j].b)
			{
				t = p[i].k[j].a;
				p[i].k[j].a = p[i].k[j].b;
				p[i].k[j].b = t;
			}
			for(i = 0
			
			vector<int> vec1 (p[i].k, p->x+n);
			vector<int>::iterator it;
			int p = -1;
			for (it=vec1.begin(); it!=vec1.end(); ++it)
			{
				if (*it != p)
				{
					
				
					
		}
		find_paths(p[i]);*/
	}

	/*for (i = 0; i < t; i++)
	{
		cout<<n[i]<<endl;
		for(j = 0; j < n[i]; j++)
		{
			cout<<p[i].k[j].a<<" "<<p[i].k[j].b<<endl;
		}
	}*/
	cout<<endl;
}
