#include <stdio.h>
#include <time.h>

void func_name()
{
	printf("Function starts \n");
	printf("Press any key to stop function\n");

	for(;;){
		if(getchar())
			break;
	}
	printf("Function ends\n");
}

int
main(int argc, char *argv[])
{
	clock_t t;
	t = clock();
	func_name();
	t = clock() - t;
	double  time_taken_by_func = ((double)t) / CLOCKS_PER_SEC;
	printf("The processing time of function if: %f\n", time_taken_by_func);
	return 0;
}
