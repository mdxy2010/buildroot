#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd;

	fd = open("/mnt/fs_test.txt", O_RDWR |O_CREAT, 0666);

	if (fd < 0) {
		printf("open fs_test file failed\n");
		return -1;
	}

	printf("close file......\n");
	close(fd);
	return 0;
}
