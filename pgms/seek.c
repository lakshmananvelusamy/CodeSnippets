#include<stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<errno.h>
#include<string.h>
#include<limits.h>
#include <stdlib.h>


main()
{
	int fd = -1, rc;
	char *path="tmp.txt";
        if ((fd = creat(path, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        {
                return 0;
        }
	close(fd);

	if ((fd = open(path, O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        {
                return 0;
        }
	rc = lseek(fd, 0, SEEK_SET);
	printf("%d\n", rc);
	rc = lseek(fd, 0, SEEK_END);
	printf("%d\n", rc);
	close(fd);
}
	

