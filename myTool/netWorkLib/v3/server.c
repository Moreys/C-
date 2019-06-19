/*************************************************************************
  @FileName:  server.c
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 12 Jun 2019 11:30:39 PM CST
 ************************************************************************/
                                                                         
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int main(void)
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);//默认情况下是阻塞的
    if(-1 == listenfd)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    //一个服务器程序关闭以后   可以马上重新启动
    int on = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    {
        perror("setsockopt error");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

#if 1
    //实现系统级别的负载均衡, 一个服务器程序可以在同一台物理主机的同一时刻启动
    if(setsockopt(listenfd, SOL_SOCKET,
                   SO_REUSEPORT, &on, sizeof(on)) < 0)
    {
        perror("setsockopt error");
        close(listenfd);
        exit(EXIT_FAILURE);
    }
#endif
    struct sockaddr_in serverAddr;
    printf("sizeof(struct sockaddr_in) = %ld \n", 
           sizeof(struct sockaddr_in));
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    
    int ret = bind(listenfd,
                   (struct sockaddr*)&serverAddr,
                   sizeof(struct sockaddr));
    if(-1 == ret)
    {
        perror("bind");
        close(listenfd);
        exit(EXIT_FAILURE);
    }
    ret = listen(listenfd, 10);
    if(-1 == ret)
    {
        perror("listen");
        close(listenfd);
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        int peerFd = accept(listenfd, NULL, NULL);
        char buff[1024] = "welcom to server.";
        ret = write(peerFd, buff, strlen(buff));

        memset(buff, 0, 1024);
        printf("> pls client data:\n");
        printf("%s\n", buff);
    }
    close(listenfd);
    return 0;
}

