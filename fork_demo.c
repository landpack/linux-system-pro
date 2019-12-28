#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int
main(int argc, char *argv[])
{
	fork();
	fork();
	printf("Run me!\n");
	return 0;
}
