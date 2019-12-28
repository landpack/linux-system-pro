#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int
main(int argc, char *argv[])
{
	printf("Linux Hint Hello \n");
	_exit(0);
	printf("Linux Hint bye!\n");

}
