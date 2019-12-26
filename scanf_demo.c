#include <stdio.h>

int
main(int argc, char *argv[])
{
	char buf[10];
	printf("Enter your first name:");
	//scanf("%s", buf);
	scanf("%10s", buf);
	
	puts(buf);
	return 0;
}
