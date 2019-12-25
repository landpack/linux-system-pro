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

	if((fptr = fopen("test.bin", "rb")) == NULL ){
		fprintf(stderr, "Openning failure!\n");
		exit(EXIT_FAILURE);
	}

	for (num  = 1; num < 5; num ++){
		fread(&number, sizeof(struct threeNumber), 1, fptr);
		printf("num1=%d\tnum2=%d\tnum3=%d\n", number.num1, number.num2, number.num3);
	}

	fclose(fptr);
	return 0;
}
