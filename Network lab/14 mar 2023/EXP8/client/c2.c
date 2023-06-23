#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 4960

void main()
{
	int clientsocket, err=0;
	char ti[100];
	struct sockaddr_in clientaddr;
	char buffer[1024];
	clientsocket=socket(PF_INET,SOCK_STREAM,0);
	if(clientsocket<0)
	{
		printf("\nCould not create socket");
		exit(0);
	}
	printf("\nSocket created succefully");
	memset(&clientaddr,'\0',sizeof(clientaddr));
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(PORT);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(connect(clientsocket,(struct sockaddr *)&clientaddr,sizeof(clientaddr))<0)
	{
		printf("\nConnection error");
		exit(0);
	}
	printf("\nConnection successfull");
	err = recv(clientsocket,ti,100,0);
	if(err<0)
	{
		printf("\nRecieving error");
		exit(0);
	}
	printf("\nData recevied succefully\nTime : %s\n",ti);
	close(clientsocket);
}
