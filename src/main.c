#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>


#include"lmdd.h"

#define	DEBUG


int recgarg(char* arg);
void send2srv();
char lmddarg[4]={"lmdd"};


void main(int argc, char* argv[]){
	int args;
	int ar;
	for(args=1; args < argc ;args++){
		switch(recgarg(argv[args])){
			case 1:	//lmdd
				ar=4;
				char*av[]={"lmdd","if=internal","of=internal","count=1000"};
				char*output = lmdd(ar,av);	
				printf("%s",output);	
			case 2:

			default:
			return;
		}	

	}	
	send2srv();
	
}

int recgarg(char* arg){
	if (!strcmp(lmddarg,arg)){
		#ifdef DEBUG
		printf("%s\n",arg);
		#endif
		return 1;
	}
	//if(!strcmp(cmd,arg)){
	//	
	//}

}

void send2srv(){
	struct sockaddr_in srv_addr;
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	memset(&srv_addr,0,sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	srv_addr.sin_port=htons(1985);
	connect(sock, (struct sockaddr*)&srv_addr, sizeof(srv_addr));

	char buffer[]="test data";
	write(sock,buffer,sizeof(buffer));
	close(sock);

}
