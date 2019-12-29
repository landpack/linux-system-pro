#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <ifaddrs.h>

#define PORT 8080


int
main(int argc, char *argv[])
{
	
	int serv_fd, n_socket, v_read;
	struct sockaddr_in address;
	
	int opt = 1;
	int addr_length = sizeof(address);
	char buffer[1024] = {0};
	
	char *hey = "Hey I am server!";

	if((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("Socket failure!");
		exit(EXIT_FAILURE);
	}

	if(setsockopt(serv_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt error!");
		exit(EXIT_FAILURE);
	}


	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	if(bind(serv_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failure");
		exit(EXIT_FAILURE);
	}

	if(listen(serv_fd, 3) < 0)
	{
		perror("listen error");
		exit(EXIT_FAILURE);
	}

	if((n_socket = accept(serv_fd, (struct sockaddr *)&address, (socklen_t*)&addr_length)) < 0)
	{

		perror("Accept error");
		exit(EXIT_FAILURE);
	}

	v_read = read(n_socket, buffer, 1024);
	printf("%s \n", buffer);
	
	send(n_socket, hey, strlen(hey), 0);
	printf("Hello Msg is sent! \n");

}
