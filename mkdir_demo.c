#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


int
main(int argc, char *argv[])
{
	int res = mkdir("./test_dir", 0777);
	if (res == 0) {

		printf("Successful\n");
	}else{
		printf("Mkdir failure\n");
	}
	return 0;
}
