
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ioctl.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<net/if.h>
void main()
{
    int socket_fd;
    struct sockaddr_in *sock_addr;
    struct ifreq ifr;

    char ip_addr[20];
    int ret;
    strcpy(ifr.ifr_name,"eth3");
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return ;
    }
    ret = ioctl(socket_fd, SIOCGIFADDR, &ifr);

    if(ret < 0)
        return;

    sock_addr = (struct sockaddr_in*)&(ifr.ifr_addr);
    strcpy(ip_addr, inet_ntoa(sock_addr->sin_addr));
    printf("ip = %s\n", ip_addr);



}
