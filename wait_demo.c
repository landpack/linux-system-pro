#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int
main(int argc, char *argv[])
{
	pid_t cpid;
	if(fork() == 0){
		exit(0);
	}else{
		cpid = wait(NULL);
	}

	printf("Parent pid=%d\n", getpid());
	printf("Child pid=%d\n", cpid);
}
