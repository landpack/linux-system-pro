#include <stdio.h>
#include <unistd.h>

int
main(int argc, char * argv[])
{
	int current_pid;
	int parent_pid;


	current_pid = getpid();
	parent_pid = getppid();

	printf("Pid=%d\t Parent pid=%d\n", current_pid, parent_pid);
	return 0;
}
