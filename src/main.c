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
char *semarg="lat_sem";
char *randarg="lat_rand";
char *opsarg="lat_ops";
char *fcntlarg="lat_fcntl";
char *fifoarg="lat_fifo";
char *fsarg="lat_fs";
char *procarg="lat_proc";
char *sigarg="lat_sig";
char *syscallarg="lat_syscall";
char *tcparg="lat_tcp";
char *unixarg="lat_unix";
char *connectarg="lat_connect";

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

			case 4://lat_sem
		
				ar=1;
				char* lat_sem_av[]={semarg};
				lat_sem(ar,lat_sem_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;

			case 5://lat_rand
		
				ar=1;
				char* lat_rand_av[]={randarg};
				lat_rand(ar,lat_rand_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
	
			case 6://lat_rand
		
				ar=1;
				char* lat_ops_av[]={opsarg};
				lat_ops(ar,lat_rand_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
	
			case 7://lat_fcntl
		
				ar=1;
				char* lat_fcntl_av[]={fcntlarg};
				lat_fcntl(ar,lat_fcntl_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
			
			case 8://lat_fifo
		
				ar=1;
				char* lat_fifo_av[]={fifoarg};
				lat_fifo(ar,lat_fifo_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
			
			case 9://lat_fs
		
				ar=3;
				char* lat_fs_av[]={fsarg, "-s", "1024"};//1k file
				lat_fs(ar,lat_fs_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
				
			case 10://lat_proc
		
				ar=2;
				char* lat_proc_av[]={procarg, "exec"};//fork+exec
				lat_proc(ar,lat_proc_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
	
			case 11://lat_sig
		
				ar=2;
				char* lat_sig_install_av[]={sigarg, "install"};//sig handler install
				char* lat_sig_overhead_av[]={sigarg, "catch"};//sig handler overhead
				lat_sig(ar,lat_sig_install_av,ret_str);
				lat_sig(ar,lat_sig_overhead_av,ret_str);

#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
	
			case 12://lat_syscall
		
				ar=2;
				char* lat_syscall_null_av[]={syscallarg, "null"};
				char* lat_syscall_read_av[]={syscallarg, "read"};
				char* lat_syscall_write_av[]={syscallarg, "write"};
				char* lat_syscall_stat_av[]={syscallarg, "stat"};
				char* lat_syscall_fstat_av[]={syscallarg, "fstat"};
				char* lat_syscall_open_av[]={syscallarg, "open"};

	

				lat_syscall(ar,lat_syscall_null_av,ret_str);
				lat_syscall(ar,lat_syscall_read_av,ret_str);
				lat_syscall(ar,lat_syscall_write_av,ret_str);
				lat_syscall(ar,lat_syscall_stat_av,ret_str);
				lat_syscall(ar,lat_syscall_fstat_av,ret_str);
				lat_syscall(ar,lat_syscall_open_av,ret_str);

#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
			case 13://lat_tcp
		
				ar=2;
			//	char* lat_tcp_server_av[]={tcparg, "-s"};//lat_tcp -s
				char* lat_tcp_localhost_av[]={tcparg, "localhost"};//lat_tcp localhost
			//	char* lat_tcp_shotdown_av[]={tcparg, "-S","localhost"};//lat_tcp -S localhost
			//	lat_tcp(ar,lat_tcp_server_av,ret_str);
				lat_tcp(ar,lat_tcp_localhost_av,ret_str);
				ar=3;
				
			//	lat_tcp(ar,lat_tcp_shotdown_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif			
				break;
			
			case 14://lat_unix
		
				ar=1;
				char* lat_unix_av[]={unixarg};
				lat_unix(ar,lat_unix_av,ret_str);
#ifdef DEBUG
				printf("main: %s\n",ret_str);
#endif				
	
				break;
	
			case 15://lat_connect
		
				ar=2;
				char* lat_connect_av[]={connectarg,"localhost"};
				lat_connect(ar,lat_connect_av,ret_str);
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

	if (strcmp(semarg,arg)==0)
		return 4;

	if (strcmp(randarg,arg)==0)
		return 5;

	if (strcmp(opsarg,arg)==0)
		return 6;

	if (strcmp(fcntlarg,arg)==0)
		return 7;

	if (strcmp(fifoarg,arg)==0)
		return 8;

	if (strcmp(fsarg,arg)==0)
		return 9;

	if (strcmp(procarg,arg)==0)
		return 10;

	if (strcmp(sigarg,arg)==0)
		return 11;
	
	if (strcmp(syscallarg,arg)==0)
		return 12;

	if (strcmp(tcparg,arg)==0)
		return 13;

	if (strcmp(unixarg,arg)==0)
		return 14;

	if (strcmp(connectarg,arg)==0)
		return 15;








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
