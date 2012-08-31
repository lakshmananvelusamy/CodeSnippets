#include<iostream>
using namespace std;

class File
{
public:
	virtual int open(char *s)
	{
		cout<<"File to be opened = "<<s<<endl;
	}

	int load(char *s, int b)
	{
		cout<<"File to be loaded = "<<s<<"b = "<<b<<endl;
	}
};

class File1:public File
{
public:
	int open(char *s)
	{
		cout<<"File1 to be opened = "<<s<<endl;
	}

	int load(char *s, int b)
	{
		cout<<"File1 to be loaded = "<<s<<"b = "<<b<<endl;
	}
};

main()
{
	File *file = new File();
	file->open("laxman.txt");
	file->load("raman.txt", 10);
}
