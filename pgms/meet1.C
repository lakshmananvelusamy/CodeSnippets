#include <iostream>

using namespace std;
struct location
{
        unsigned int x,y;
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
        unsigned int n;
        register unsigned long long min, d;
        register unsigned int i, j;
        unsigned int x, y;
        location *p;
        min = ~0;
        fflush(stdin);
        cin>>n;
        p = new location[n];
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
                        x = p[i].x > p[j].x ? p[i].x - p[j].x : p[j].x - p[i].x;
                        y = p[i].y > p[j].y ? p[i].y - p[j].y : p[j].y - p[i].y;
                        d += x>y?x:y;
                }
                if (d < min)
                {
                        min = d;
                }
        }
        cout<<min<<endl;
}
