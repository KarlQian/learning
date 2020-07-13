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
#include <sys/sem.h>
#include <sys/mman.h>
#include "common.h"
union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };


int sem_create(key_t key){
    // semid=semget(IPC_PRIVATE,1,0666|IPC_CREAT);

    int semid = 0;
    if ((semid=semget(key,1,0666|IPC_CREAT))<0)
    {
    perror("semget:");
    return -1;
    }
    return semid;
}

int sem_open(key_t key){
    int semid = 0;
    if (semid=semget(0x1111,1,0666)<0)
    {
    perror("semget:");
    return -1;
    }
    return semid;
}
int sem_setval(int semid, int val){
    union semun su;
    su.val = val;
    int ret = semctl(semid,0, SETVAL,su);
    return ret;
}

int sem_getval(int semid){
    union semun su;
    int ret = semctl(semid,0, GETVAL,su); // address 
    int val = su.val;

    return val;
}

int sem_p(int semid)
{   
    struct sembuf sb_p = {0,-1,SEM_UNDO}; // sem nubmer, operation(-1),flag : 0 default  IPC_NOWAIT
        // unsigned short sem_num;  /* semaphore number */
        //    short          sem_op;   /* semaphore operation */
        //    short          sem_flg;  /* operation flags */
    return semop(semid,&sb_p,1); //id , buf , nuumber
}
int sem_v(int semid)
{
    struct sembuf sb_v = {0,1,SEM_UNDO}; // sem nubmer, operation(+1),flag : 0 default  IPC_NOWAIT
        // unsigned short sem_num;  /* semaphore number */
        //    short          sem_op;   /* semaphore operation */
        //    short          sem_flg;  /* operation flags */
    return semop(semid,&sb_v,1); //id , buf , nuumber
    
}

 int readdata(int confd,char* data, int len)
 {
     int ret = recv(confd,data,len,NULL);
     if (ret <0)
     {perror("recv error"); return -1;}
     else{
         //printf("received data%s\n",*data);
            printf("received data, size:%d data:%s", ret,data);     
        } 
     return ret;
 }


int main(){
    int ret = 0;
    int semid =sem_create(0x6667);
    sem_setval(semid, 1);

    int* p_map = (int*)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED| MAP_ANONYMOUS,-1,0);
    int listenfd  = socket(AF_INET,SOCK_STREAM,0) ;
    if (listenfd<0){perror("socket");return -1;}

    int flag = 0;
    if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&flag,sizeof(flag))<0)
    {
        perror("setsocket");
        exit(1);
    }

    struct sockaddr_in serv_addr, client_addr; // use sockaddr_in to define the ip addresss the convert to
    //serv_addr.sin_addr = inet_addr(ipAddress); // inet_addr : change to  network format
    inet_pton(AF_INET,ipAddress,(void*)&serv_addr.sin_addr);  // inet_pton :convert ip address from text to binary
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port =htons(port);
    socklen_t addr_size = sizeof(serv_addr);

    ret = bind(listenfd,(struct sockaddr*)&serv_addr,addr_size);
    if (ret < 0){
        perror("bind");
        return -1;}
    if (listen(listenfd,1024)<0){perror("listen");}
    int confd = -1;
        printf("accept before "); 
    while (1){
        confd = accept(listenfd,NULL,NULL);
        printf("accept after\n "); 
        if (confd<0){
        perror("accept error "); 
        return -1;
        }
        else
        {                 
        int pid = fork();
        if (pid ==0)
        {
            printf("child\n");
            char data[1024];
            close(listenfd);
            sem_p(semid);
            (*p_map)++;
            printf("connection number: %d\n",*p_map);
            sem_v(semid);
            munmap(p_map,sizeof(int));
            readdata(confd,data,10);
            exit(0);                                       
        }
        else if (pid>0)
        {
            printf("father\n");
            close(confd);
        }
        else 
        {perror("fork error:"); return -1;}
    }
    }
    close(listenfd);
    wait();
}