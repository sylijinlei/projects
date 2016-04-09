#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define UDP_PORT 3434

void main(){
	int client_fd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t socket_len;
	size_t recv_len;
	char buffer[100];

	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(UDP_PORT);
	server_addr.sin_addr.s_addr = inet_addr("192.168.40.134");

	client_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == client_fd){
		perror("Create socket failed!\n");
		exit(1);
	}
	char *send_string = "send string\n";
	strncpy(buffer, send_string, strlen(send_string));
	if(sendto(client_fd, buffer, strlen(send_string),0, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0){
		perror("send data failed!\n");
		exit(1);
	}
	close(client_fd);
}
