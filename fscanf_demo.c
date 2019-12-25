#include <stdio.h>
#include <stdlib.h>


int
main(int argc, char *argv[])
{
	int num;
	FILE *fptr;
	
	if((fptr = fopen("test.txt", "r")) == NULL){
		fprintf(stderr, "Failure to open file\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fptr, "%d", &num);
	printf("the value of n=%d\n", num);
	fclose(fptr);
	return 0;
}
