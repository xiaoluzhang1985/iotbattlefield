#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	struct sockaddr_in srv_addr;
	struct sockaddr_in clnt_addr;

	int srv_sock = socket(AF_INET, SOCK_STREAM,0);
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr =inet_addr("127.0.0.1");
	srv_addr.sin_port = htons(1985);
	
	bind((srv_sock), (struct sockaddr*)&srv_addr, sizeof(srv_addr));
	
	listen(srv_sock,20);
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	int clnt_sock = accept(srv_sock, (struct sockaddr*)& clnt_addr, &clnt_addr_size);
	
	char buffer[180];
	read(clnt_sock,buffer,sizeof(buffer));
	printf("%s\n",buffer);
	close(srv_sock);
	
	return 0;
}
