#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY 0x1111

union semun {
	int value;
	struct semid_ds *buf;
	unsigned short *array;
};

struct sembuf a = {0, -1, SEM_UNDO};
struct sembuf b = {0, +1, SEM_UNDO};

int
main(int argc, char *argv[])
{
	int id = semget(KEY, 1, 0666 | IPC_CREAT);

	if (id < 0){
		perror("semget error");
		exit(EXIT_FAILURE);
	}
	union semun su;
	su.value =1;

	if (semctl(id, 0, SETVAL, su) < 0)
	{
		perror("semctl error");
		exit(EXIT_FAILURE);
	}

	int pid;
	pid = fork();
	srand(pid); // init seed
	if(pid < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if (pid) {
		char *se = "abc";
		int l = strlen(se);
	
		for(int i=0; i < l; ++i)
		{
			if(semop(id, &a, 1) < 0)
			{
				perror("semop error with a");
				exit(EXIT_FAILURE);
			}
			putchar(se[i]);
			fflush(stdout);
			sleep(1);
			putchar(se[i]);
			fflush(stdout);
			if(semop(id, &b, 1) < 0) {
				perror("semop error");
				exit(EXIT_FAILURE);
			}
			sleep(1);
	    }
	}else{
		char *se = "abc";
		int l = strlen(se);
	
		for(int i=0; i < l; ++i)
		{
			if(semop(id, &a, 1) < 0)
			{
				perror("semop error with b");
				exit(EXIT_FAILURE);
			}
			putchar(se[i]);
			fflush(stdout);
			sleep(1);
			putchar(se[i]);
			fflush(stdout);
			if(semop(id, &b, 1) < 0) {
				perror("semop error");
				exit(EXIT_FAILURE);
			}
			sleep(1);


		}
	}
}
