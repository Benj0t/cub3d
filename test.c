#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int ko(int fd)
{
	char *str;
	printf("%zd\n", read(fd,str,10));
	return (0);
}

int main()
{
	char *str;
	int fd;

	fd = 0;
	fd = open("test", O_RDONLY);
	printf("%d\n", fd);
	printf("%zd\n",read(fd, str, 100));
	ko(fd);
	return (0);
}
