#include<stdio.h>
#include<iostream>
using namespace std;

class A
{
public:
static int a;
	A()
	{
		cout<<++A::a<<endl;
	}
};

main(int argc, char *argv[])
{
	int n;
	sscanf(argv[1], "%d", &n);
	A obj[n];
}
