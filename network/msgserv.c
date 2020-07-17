
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/msg.h>
#include "common.h"
struct msg_buf
{
    long mtype;
    char data[255];
};
echo(int msgid , struct msg_buf* buf){
	char* data= buf->data;
	long type = buf->mtype;

	
	if ( type == REQUEST){
		struct msg_buf msgsnd_buf;
		msgsnd_buf.mtype = atoi(data); // use data.pid to distinginsh different client
		sprintf(msgsnd_buf.data,"response:%d",msgsnd_buf.mtype);

		int ret = msgsnd(msgid,&msgsnd_buf, sizeof(msgsnd_buf.data), IPC_NOWAIT);
		if (ret <0){
			perror("server: msgsnd:");
			return -1;
		}

	}
}
int main(){
    int msgid;
    int ret;
    pid_t pid;
	struct msg_buf msgrcv_buf;
    msgid=msgget(key, IPC_CREAT|0666); 
    if(msgid==-1)
    {
		// if (errno == EEXIST){
		// 	if (msgctl(msgid,IPC_RMID,NULL)<0){
		// 		perror("RMID:");
		// 		return -1;
		// 	}
		// 	else{
    	// 		msgid=msgget(key, IPC_CREAT|IPC_EXCL|0666); 
		// 		}
		// }
		// else {
			perror("msget: \n");
			return -1;

	}
    		
	while (1)
	{
		ret= msgrcv(msgid, &msgrcv_buf, sizeof(msgrcv_buf.data),0,0);
		if (ret <0){
			perror("server: msgrcv:");
			return -1;
		}
		printf("serv: recive message:%s",msgrcv_buf.data);
		echo(msgid,&msgrcv_buf);
	}


   
}