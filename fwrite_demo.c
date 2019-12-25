#include <stdio.h>
#include <stdlib.h>

struct threeNumber {
	int num1, num2, num3;
};


int
main(int argc, char *argv[])
{
	int num;
	FILE *fptr;
	struct threeNumber number;

	if((fptr = fopen("test.bin", "wb")) == NULL ){
		fprintf(stderr, "Openning failure!\n");
		exit(EXIT_FAILURE);
	}

	for (num  = 1; num < 5; num ++){
		number.num1 = num;
		number.num2 = num * 2;
		number.num3 = num * num;		
	}
	fwrite(&number, sizeof(struct threeNumber), 1, fptr);
	fclose(fptr);
	return 0;
}
