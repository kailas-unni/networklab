#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#define PORT 4960

void main()
{
	int sockfd, err=0;
	char haiku[200]="Long hard rain\nHanging in the willows\nTender new leaves";
	struct sockaddr_in serveraddr;
	int newsocket;
	struct sockaddr_in newaddr;
	socklen_t addr_size;
	char buffer[20];
	sockfd=socket(PF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("\nCould not create socket");
		exit(0);
	}
	printf("\nSocket created successfully");
	memset(&serveraddr,'\0',sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(PORT);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr))<0)
	{
		printf("\nBinding error");
		exit(0);
	}
	printf("\nBinding successfull");
	if(listen(sockfd,5)<0)
	{
		printf("\nError in listening");
		exit(0);
	}
	printf("\nListening successull");
	addr_size=sizeof(newsocket);
	newsocket=accept(sockfd,(struct sockaddr *)&newaddr,&addr_size);
	if(newsocket<0)
	{
		printf("\nError in connection");
	}
	printf("\nConnection successfull");
	err = send(newsocket,haiku,200,0);
	if(err<0)
	{
		printf("\nSending error!!");
		exit(0);
	}
	printf("\nResponding to client with a haiku\n");
	close(sockfd);
}
	
