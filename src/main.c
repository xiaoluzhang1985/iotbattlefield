#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

#include"headers.h"


//#define	DEBUG


int recgarg(char* arg);
void send2srv();
char *lmddarg ="lmdd";
char *pipearg ="lat_pipe";
char *selectarg="lat_select";

void main(int argc, char* argv[]){
	int args;
	int ar;

	char* ret_str=(char *)malloc(800);

	for(args=1; args < argc ;args++){

		switch(recgarg(argv[args])){
			case 1:	//lmdd
				ar=4;
				char* lmdd_av[]={lmddarg,"if=internal","of=internal","count=1000"};

				lmdd(ar,lmdd_av, ret_str);		
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif
				
				break;
			case 2://lat_pipe
				ar=1;
				char* lat_pipe_av[]={pipearg};
				lat_pipe(ar,lat_pipe_av,ret_str);
				
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif
		
	
				break;
			case 3://lat_select
		
				ar=4;
				char* lat_select_av[]={selectarg,"-n","10","file"};
				lat_select(ar,lat_select_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;

			default:
				break;
			
		}
	}
	//printf("%s",ret_str);
	//printf("length %d",strlen(ret_str));
	send2srv(ret_str);
	free(ret_str);		
}

int recgarg(char* arg){
	#ifdef DEBUG
	printf("argument is %s\n",arg);
	#endif
	

	if (strcmp(lmddarg,arg)==0)
		return 1;
	
       	if (strcmp(pipearg,arg)==0)
		return 2;

	if (strcmp(selectarg,arg)==0)
		return 3;
	//else if(!strcmp(cmd,arg)){
	//	
	//}
return -1;
}

void send2srv(char *text){
	struct sockaddr_in srv_addr;
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&srv_addr,0,sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	srv_addr.sin_port=htons(1985);
	connect(sock, (struct sockaddr*)&srv_addr, sizeof(srv_addr));
	write(sock,text,strlen(text));
	close(sock);

}
