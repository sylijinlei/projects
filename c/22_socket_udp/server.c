#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define UDP_PORT 3434

void main(){
	int server_fd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t socket_len;
	size_t recv_len;
	char buffer[100];
	printf("I am receiving data...");

	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(UDP_PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == server_fd){
		perror("Create socket failed!\n");
		exit(1);
	}
	if((bind(server_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)){
		perror("Server bind failed!");
		exit(1);
	}

    while(1){
    {
		printf("I am receiving data...");
		if((recv_len = recvfrom(server_fd, buffer, 20, 0, (struct sockaddr *)&client_addr, &socket_len)) == -1){
			perror("Receive data failed!\n");
			exit(1);
		}else{
			printf("Recv data from client, client addr = %s, data size = %d, data = %s\n",
					inet_ntoa(client_addr.sin_addr), (int)recv_len, buffer);
		}


	}

}
