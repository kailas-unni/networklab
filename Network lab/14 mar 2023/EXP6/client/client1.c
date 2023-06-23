#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
	int sid,cid,rid,seid,wc=0;
	char buff[50];
	struct sockaddr_in server;
	int addrlen=sizeof(server);
	sid=socket(AF_INET,SOCK_STREAM,0);
	if(sid<0)
	{
		printf("Socket Creation Failed :\n");
		exit(1);
	}
	else
	{
		printf("Socket Creation Successful \n");
	}
	server.sin_family=AF_INET;
	server.sin_port=htons(7000);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	cid=connect(sid,(struct sockaddr *)&server,addrlen);
	if(cid<0)
	{
		printf("connection Unsuccesful :\n");
		exit(1);
	}
	else
	{
		printf("Connection Successful\n");
	}
	strcpy(buff,"stop");
	while(strcmp(buff,"start")!=0)
	{
		printf("\nEnter 'start' to begin : ");
		scanf("%s",buff);
	}
	printf("---------CHAT STARTED---------\n");
	while(1)
	{
		printf("You  : ");
		scanf(" %[^\n]s",buff);
		wc++;
		if(wc>25)
		{
			printf("You have already 25 messages today !! come back tomorrow :)\n");
			printf("Disconnecting from Server \n");
			strcpy(buff,"stop");
			seid=send(sid,buff,sizeof(buff),0);			
			break;
			close(sid);			
		}
		seid=send(sid,buff,sizeof(buff),0);
		if(seid<0)
		{
			printf("Send Failed \n");
			exit(1);
		}		
		if(strcmp(buff,"stop")==0)
		{
			printf("Disconnecting from Server \n");
			close(sid);
			exit(1);
		}		


		rid=recv(sid,&buff,sizeof(buff),0);
		if(rid<0)
		{
			printf("Receive failed\n");
			exit(1);
		}
		printf("Them : %s\n",buff);
	}
	return 0;
			
}
