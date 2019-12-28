#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	char *args[] = {"./execvp", NULL};
	execvp(args[0], args);
}
