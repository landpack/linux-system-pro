#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define INTERVAL 500

void
doSomething(int);

int
main(int argc, char *argv[])
{
	struct itimerval it_val;
	if(signal(SIGALRM, (void (*)(int)) doSomething) == SIG_ERR)
	{
		perror("Unable to catch SIGALRM");
		exit(1);
	}

	it_val.it_value.tv_sec = INTERVAL / 1000;
	it_val.it_value.tv_usec = (INTERVAL * 1000) % 1000000;
	
	it_val.it_interval = it_val.it_value;
	if (setitimer(ITIMER_REAL, &it_val, NULL) == -1)
	{
		perror("Error calling setitimer()");
		exit(1);
	}

	for(;;)
		pause();
	return 0;
}

void
doSomething(int signum)
{
	printf("Timer end\n");
}
