#include <stdio.h>
#include <stdlib.h>


int
main(int argc, char * argv[])
{
	int num;
	FILE *fptr;
	fptr = fopen("test.txt", "w");
	if (fptr == NULL){
		fprintf(stderr, "Create file failure\n");
		exit(-1);
	}
	printf("Enter a num:");
	scanf("%d", &num);
	fprintf(fptr, "%d", num);
	fclose(fptr);
	return 0;
}
