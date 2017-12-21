#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int fd,ret;
	uint32_t *buf = (uint32_t*)malloc(1024);

	memset(buf,0xaa, sizeof(uint32_t) * 1024);

	printf("======================== start open =========================\n");
	fd = open("/mnt/fs_test.txt", O_RDWR | O_CREAT, 0666);
	printf("======================== end   open =========================\n");

	if (fd < 0) {
		printf("open fs_test file failed\n");
		return -1;
	}

	printf("======================== start write  =========================\n");
	ret = write(fd,buf,sizeof(uint32_t)*1024);
	if (ret != 4096) {
		printf("write file failed ret = %d\n", ret);
		free(buf);
		close(fd);
		return -1;
	}
	printf("======================== end  write  =========================\n");
	printf("close file......\n");
	free(buf);
	close(fd);
	return 0;
}
