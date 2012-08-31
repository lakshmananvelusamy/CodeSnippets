#include <iostream>

using namespace std;
struct location
{
	long long x,y;
};

/*long long distance(location p1, location p2)
{
	long long x, y;
	x = p1.x > p2.x ? p1.x - p2.x : p2.x - p1.x;
	y = p1.y > p2.y ? p1.y - p2.y : p2.y - p1.y; 
	return x>y?x:y;
}*/
	
int main()
{
	register unsigned long long min, d;
	register unsigned long long i, j;
	register long long n;
	unsigned long long **memo;
	location *p;
	min = ~0;
	fflush(stdin);
	cin>>n;
	p = new location[n]();
	memo = new unsigned long long *[n]();
	for(i = 0; i < n; i++)
	{
		memo[i] = new unsigned long long[n]();
	}
//	memo = (unsigned long long **)calloc(n, sizeof(long long) * n);
	for(i = 0; i < n; i++)
	{
		fflush(stdin);
		cin>>p[i].x>>p[i].y;
	}
	
	for(i = 0; i < n; i++)
	{
		d = 0;
		for (j = 0; j < n; j++)
		{
			if (memo[i][j] == 0)
			{
				unsigned long long x, y, t;
				x = p[i].x > p[j].x ? p[i].x - p[j].x : p[j].x - p[i].x;
				y = p[i].y > p[j].y ? p[i].y - p[j].y : p[j].y - p[i].y;
				t = x>y?x:y;
				d += t;
				memo[j][i] = t;
			}
			else d += memo[i][j];
		}
		if (d < min)
		{
			min = d;
		}
	}
	cout<<min<<endl;
	for(i = 0; i < n; i++)
	{
		delete []memo[i];
	}
	delete []memo;
	delete p;
	return min;
}	
