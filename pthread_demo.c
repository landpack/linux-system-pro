#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//gcc pthread_demo.c -lpthread

void 
*ThreadFunc(void *vargp)
{
	sleep(2);
	printf("Hell Threading\n");
	return NULL;;
}

int
main(int argc, char *argv[])
{
	pthread_t thread_id;
	printf("Earlier when didn't use threading\n");
	pthread_create(&thread_id, NULL, ThreadFunc, NULL);

	pthread_join(thread_id, NULL);
	printf("After when we have used threading\n");
	exit(0);
}

