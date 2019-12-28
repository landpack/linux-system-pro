#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int
main(int argc, char *agrv[])
{
	char fn[] = "linuxtemp.fifo";
	char out[100] = "This is FIFO and this is linux\n";
	char in[100];
	int rf, wf;

	if (mkfifo(fn, S_IRWXU) != 0)
	{
		perror("mkfifo() failure");
	}else{
		if(( rf = open(fn, O_RDONLY | O_NONBLOCK)) < 0)
			perror("open() error while on the writing end");
		else
		{

			if(write(wf, out, strlen(out) + 1) == -1)
				perror("write failure");
			else if (read(rf, in, sizeof(in)) ==  -1)
				perror("read failure");
			else
			{
				printf("reading '%s' from FIFO\n", in);

			}
			close(wf);

		}
			close(rf);
	}
	unlink(fn);
}
