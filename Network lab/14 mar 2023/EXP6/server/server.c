#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
int main()
{
	int sid,bid,lid,aid,rid,seid,n=0,y=1;
	struct sockaddr_in server;
	int addrlen=sizeof(server);
	char buff[50];
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
	bid=bind(sid,(struct sockaddr *)&server,addrlen);
	if(bid<0)
	{
		printf("Bind Unsuccesful :\n");
		exit(1);
	}
	else
	{
		printf("Bind Successful\n");
	}
	lid=listen(sid,5);
	if(lid<0)
	{
		printf("Listen failed \n");
		exit(1);
	}
	while(y)
	{
		printf("\n---------Waiting for client---------");
		strcpy(buff,"");
		aid=accept(sid,(struct sockaddr *)&server,(socklen_t *)&addrlen);
		n++;
		if(aid<0)
		{
			printf("Accept Failed \n");
			exit(1);
		}
		printf("\nConnected to client%d \n",n);
		while(1)
		{
			rid=recv(aid,buff,sizeof(buff),0);
			if(rid<0)
			{
				printf("Receive failed \n");
				exit(1);
			}
			if(strcmp(buff,"stop")==0)
			{
				printf("Disconnected from Client \n");
				break;
			}
			else
			{
				printf("Them  : %s\n",buff);
				printf("You  : ");
				scanf(" %[^\n]s",buff);
				seid=send(aid,buff,sizeof(buff),0);
				if(seid<0)
				{
					printf("Send Failed \n");
					exit(1);
				}			
			}
		}
		printf("Do you want to continue(1/0) : ");
		scanf("%d",&y);
	}
	close(sid);	
	return 0;

}


