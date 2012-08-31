/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int main()
{
        register int i, j, k, z;
	register int t, *n, mod;
        unsigned int *m;
        register int **a, **b;
        cin>>t;
        a = new int*[t];
        b = new int*[t];
        n = new int[t];
        m = new unsigned int[t];
for(z = 0; z < t; z++)
{
        cin>>n[z]>>m[z];
        a[z] = new int[n[z]+2];
        b[z] = new int[n[z]+2];
        for(i = 1; i <= n[z]; i++)
        {
                cin>>a[z][i];
        }
}
for(z = 0; z < t; z++)
{
        mod = n[z]+1;
        a[z][0] = a[z][n[z]];
        a[z][n[z]+1] = a[z][1];

        for (k = 1; k <= n[z]; k++)
        {
                memcpy(b[z], a[z], (n[z]+2) * sizeof(int));
                for(i = 1; i <= m[z]; i++)
                {
                        j = (k+i-2) % n[z] +1;
                        b[z][j] = b[z][j]+b[z][j-1]+b[z][j+1];
                        if(j == 1) b[z][mod] = b[z][1];
                        else if (j == n[z]) b[z][0] = b[z][n[z]];
                }
                for(j = 1; j <= n[z]; j++)
                        cout<<b[z][j]%1000000007<<" ";
                cout<<endl;
        }
}
for(z = 0; z < t; z++)
{
        delete []a[z];
        delete []b[z];
}
delete []n;
delete []m;
delete []a;
delete []b;
        return 0;
}

