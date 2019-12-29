#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	struct flock flk = {F_WRLCK, SEEK_SET, 0, 0, 0};
	
	int fd;
	flk.l_pid = getpid();

	if (argc > 1)
		flk.l_type = F_RDLCK;
	
	if((fd = open("test_lock.txt", O_RDWR)) == -1)
	{
		perror("Error in opening file");
		exit(0);
	}
	printf("Hit Enter to Lock the file\n");
	getchar();
	
	printf("Checking if we could lock the file or not\n");

	if(fcntl(fd, F_SETLKW, &flk) == -1){
		perror("fcntl error");
		exit(EXIT_FAILURE);
	}

	printf("We have locked it successfuly \n");
	printf("Hit Enter Unlock the file!\n");
	
	getchar();

	flk.l_type = F_UNLCK;

	if(fcntl(fd, F_SETLK, &flk) == -1){
		perror("fcntl error");
		exit(EXIT_FAILURE);
	}

	printf("Yes, File has been Unlocked!\n");
	return 0;
}
