#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/statvfs.h>

int
main(int argc, char *argv[])
{
	struct statvfs buf;
	if (statvfs(".", &buf) == -1) {
		perror("Error\n");
		exit(EXIT_FAILURE);
	}else{
		printf("Each block has %ld bytes \n", buf.f_frsize);
		printf("There are %ld blocks available out of %ld\n", buf.f_bavail, buf.f_blocks);
	}
	
	return 0;
}
