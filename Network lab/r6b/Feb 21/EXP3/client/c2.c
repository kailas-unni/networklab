#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 4955

void main()
{
	int clientsocket;
	struct sockaddr_in clientaddr;
	char buffer[1024];
	clientsocket=socket(PF_INET,SOCK_STREAM,0);
	memset(&clientaddr,'\0',sizeof(clientaddr));
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(PORT);
	clientaddr.sin_addr.s_addr=inet_addr("172.20.33.40");
	connect(clientsocket,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
	recv(clientsocket,buffer,1024,0);
	printf("Data recevied: %s\n",buffer);
	close(clientsocket);
}
