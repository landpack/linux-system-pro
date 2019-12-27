#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void
sighandler(int);

int
main(int argc, char *argv[])
{
	signal(SIGINT, sighandler);

	for(;;)
	{
		printf("Sleeping....\n");
		sleep(2);
	}

	return 0;
}

void sighandler(int signum)
{
	printf("Caught signal %d, and now I am exiting...\n", signum);
	exit(EXIT_SUCCESS);
}
