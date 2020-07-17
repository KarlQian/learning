
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/msg.h>
#include "common.h"
struct msg_buf
{
    long mtype;
    char data[255];
};

int main(){
    int msgid;
    int ret;
    pid_t pid;
	struct msg_buf msgbuf;
    msgid=msgget(key, IPC_CREAT |0666); 
    if(msgid==-1)
    {
			perror("msget: \n");
			return -1;
	}
		
	for (int i=0;i<Num;++i){
		pid = fork();
		if (pid <0){
			perror("for error;");
			return -1;
		}

		else if (pid == 0){
			pid_t pidnumber = getpid();
			printf("children%d\n",pidnumber);
			msgbuf.mtype = REQUEST; //        getpid();
			//strcpy(msgbuf.data,"request");
			sprintf(msgbuf.data,"%d",pidnumber);
			//itoa(pidnumber,msgbuf.data,10);
			ret = msgsnd(msgid,&msgbuf, sizeof(msgbuf.data),IPC_NOWAIT);
			if(ret==-1)
			{
					printf("client send message err\n");
					perror("clienjt:send err\n");
					return -1;
			}
			struct msg_buf msgrecv;

    		ret= msgrcv(msgid, &msgrecv, sizeof(msgrecv.data), pidnumber,0); // only check the message sent to me , use pidnumber to distingish
			if(ret==-1)
			{
					printf("client : recv message err\n");
					perror("client:recv err:");
					return -1;
			}
			else{
				printf("recv:%s",msgrecv.data);
			}
			printf("finish client %d\n",i);
			
		}

		else {
		printf("father%d\n",getpid());
		}
	}
	wait(0);
	printf("finish\n");
   
}