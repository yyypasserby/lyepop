/*************************************************************************
    > File Name: net_head.h
    > Author: yaoyiyun
    > Mail: yiyunyao@sina.cn
    > Created Time: 2013年08月26日 星期一 13时39分15秒
 ************************************************************************/

#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define ETH_INTERFACE_NAME "eth0"

void createSocket(int *socketfd, int TYPE);
void zeroinAddr(struct sockaddr_in *addr);
void initMyAddr(struct sockaddr_in *addr, const int myport);
void initHostAddr(struct sockaddr_in *addr, const int myport);
void initAddr(struct sockaddr_in *addr, char *ipaddress, const int myport);
void bindPort(int *socketfd, struct sockaddr_in *addr);
void listenPort(int *socketfd);
void getAccept(int *socketfd, int *connect_socketfd,
               struct sockaddr_in *cli_addr, int *cli_addr_size);
int recvPackage(int *connect_socketfd, void *buf, int bufsize);
void getConnect(int *socketfd, struct sockaddr_in *pin_addr);
void sendMessage(int *send_socket, void *buf, int bufsize);
char *gethostIP(char *addr);
int recvPackageFrom(int *connectfd, void *buf, struct sockaddr_in *send_addr,
                    int bufsize);
void sendMessageTo(int *connectfd, void *buf, struct sockaddr_in *dest_addr,
                   int bufsize);
