#include <stdio.h>


int
main(int argc, char *argv[])
{
	char buff[BUFSIZ];
	FILE *fp = popen("ls", "r");
	
	while(fgets(buff, BUFSIZ, fp) != NULL)
	{
		printf("LS: %s\t", buff);
	}
	puts("\n");
	pclose(fp);
	return 0;
}
