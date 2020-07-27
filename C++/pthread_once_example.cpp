#include <semaphore.h>
#include <sys/types.h>
#include <dirent.h>
#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
pthread_once_t once = PTHREAD_ONCE_INIT;

void once_run(){
    printf("once run in thread%d\n",pthread_self());
}

void* task1(void* arg){
    int tid = pthread_self();
    printf("thread1 enter%d:\n",tid);
    pthread_once(&once,once_run);
    printf("thread1 return%d:\n",tid);
    return NULL;
}

void* task2(void* arg){
    int tid = pthread_self();
    printf("thread2 enter%d:\n",tid);
    pthread_once(&once,once_run);
    printf("thread2 return%d:\n",tid);
    return NULL;
}

int main(int argc , char* argv[]){
    pthread_t thrd1;
    pthread_t thrd2;
    pthread_create(&thrd1,NULL,task1,NULL);
    pthread_create(&thrd2,NULL,task2,NULL);
    sleep(3);
    printf("exit");
    return  0; 
}