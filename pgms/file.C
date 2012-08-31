#include<iostream>
#include<stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<errno.h>
#include<string.h>

using namespace std;

class Header_V1
{
        friend class DBFile;
private:
        /* Version Number of the file */
        short version;
        /* File type : heap / sorted / B+ Tree */
        short type;
        /* No of pages present in the file */
        off_t pagecount;
        /* total size of the file */
        size_t size;
        /* File creation time */
        time_t ctime;
        /* Last access time stamp */
        time_t atime;
        /* Last modification time stamp */
        time_t mtime;
public :
	Header_V1(short v, short t, off_t p, size_t s, time_t c, time_t a, time_t m)
	{
		version = v;
		type = t;
		pagecount = p;
		size = s;
		ctime = c;
		atime = a;
		mtime = m;
	}
	Header_V1(){}
};

class DBFile
{
private:
	Header_V1 *hdr;
	int mFD;
public:
	int create(char *filename)
	{
	char f[1024];
	strcpy(f, filename);
	strcat(f, ".meta");
        if ((mFD = creat(f, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        {
                cerr << "create() failed. ERRNO = " << errno << "\n";
                return 0;
        }
        time_t t;
        time(&t);
        hdr = new Header_V1(1, 0, 0, 0, t, t, t);
        lseek (mFD, 0, SEEK_SET);
        write (mFD, hdr, sizeof(Header_V1));
	cout<<"Version = "<<hdr->version<<"\n";
        if (close(mFD) == -1)
        {
                cerr << "Meta File close() failed!. ERRNO = " << errno << "\n";
                return 0;
	}
	delete hdr;
	}
	
	int openfile(char *filename)
	{
		char f[1024];
		strcpy(f, filename);
		strcat(f, ".meta");
		mFD = open(f, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	}
	void readfile()
	{
		Header_V1 h;
        	lseek (mFD, 0, SEEK_SET);
		read(mFD, (void *)&h, sizeof(Header_V1));
		cout<<"Sizeof (Header_V1) = "<<sizeof(Header_V1)<<"\n";
		cout<<"Version = "<<h.version<<"\n";
	}
	
};

	
	
main()
{
	DBFile obj;
	obj.create("laxman");
	obj.openfile("laxman");
	obj.readfile();	
}
	
