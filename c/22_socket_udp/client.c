#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define UDP_PORT 3434

void main(int args, char **argv){
    int client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t socket_len;
    size_t recv_len;
    char buffer[100];
    if(args < 2){
    	perror("Usage:\n     ./client server_ip");
    	exit(1);
    }
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(UDP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    
    memset(&client_addr, 0, sizeof(struct sockaddr_in));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(3435);
/*    client_addr.sin_addr.s_addr = inet_addr("192.168.43.170");*/
      /*  client_addr.sin_addr.s_addr = inet_addr("192.168.3.7");
*/

        client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    /*client_addr.sin_addr.s_addr = htonl(INADDR_ANY);*/


    client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == client_fd){
        perror("Create socket failed!\n");
        exit(1);
    }

    if(bind(client_fd, (struct sockaddr*)&client_addr, sizeof(struct sockaddr)) == -1){
        perror("bind error!\n");
        exit(1);
    }

    char *send_string = "client string\n\0";
    strncpy(buffer, send_string, strlen(send_string));
    printf("len = %d\n", strlen(send_string));
    if(sendto(client_fd, buffer, strlen(send_string),0, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0){
        perror("send data failed!\n");
        exit(1);
    }
    if((recv_len = recvfrom(client_fd, buffer, 100, 0, (struct sockaddr*)&server_addr, &socket_len)) == -1){
    	perror("receive error!\n");
    	exit(1);
    }else{
    	buffer[recv_len] = '\0';
    	printf("reponse from server, server addr = %s, port = %d, data size = %d, data = %s\n",
    			inet_ntoa(server_addr.sin_addr), ntohs(client_addr.sin_port), (int)recv_len, buffer);
    }
    close(client_fd);
}
