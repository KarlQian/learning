#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/mman.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include "common.h"
//       int connect(int sockfd, const struct sockaddr *addr,
   //                socklen_t addrlen);

 int writedata(int confd,char* data, int len)
 {

     int ret = send(confd,data,len,NULL);
     if (ret <0){
        perror("recv error"); return -1;}
     else{
         //printf("send data");
        printf("send data%s\n",data);

     }
     return ret;
 }

void* startConnect(void* args){
    struct sockaddr_in serv_addr= *(struct sockaddr_in*)args;

    int clientfd  = socket(AF_INET,SOCK_STREAM,0) ;
     if (clientfd<0){perror("socket");return -1;}
    int ret = connect(clientfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    if (ret<0){
    perror("connect");return -1;}

    char data[1024] = "hello\0";
    printf(" data%s\n",data);
    
    writedata(clientfd,data,10);

}

int main(){
   pthread_t p [Num];
    struct sockaddr_in serv_addr; // use sockaddr_in to define the ip addresss the convert to
    serv_addr.sin_family = AF_INET;
    //serv_addr.sin_addr = inet_addr(ipAddress); // inet_addr : change to  network format
    inet_pton(AF_INET,ipAddress,(void*)&serv_addr.sin_addr);  // inet_pton :convert ip address from text to binary
    serv_addr.sin_port =htons(port);
    socklen_t addr_size = sizeof(serv_addr);

    for (int i=0;i<Num;++i){
         pthread_create(&p[i], NULL, startConnect, &serv_addr);
        //sleep(1); //wait for rec
    }

    int retThread = 0;
    for (int i=0;i<Num;++i){
        retThread = pthread_join(p[i], (void*)&serv_addr);
        if (retThread<0){
            perror("thread join error in %d");}
        else{
            printf("finish client % d\n",i);
        }

    }
    return 0;
}