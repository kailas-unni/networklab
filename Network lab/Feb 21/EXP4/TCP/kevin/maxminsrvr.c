#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#define PORT 8000


void main()
{
	float avg;
	int nsock,min,max,arr[50];
	struct sockaddr_in srvrsock;
	int csock;
	struct sockaddr_in csckt;
	socklen_t addr_size;
	nsock=socket(AF_INET,SOCK_STREAM,0);
	if(nsock==-1)
		printf("\nSocket creation unsuccessful");
	else
		printf("\nSocket creation successful");
	memset(&srvrsock,'\0',sizeof(srvrsock));
	srvrsock.sin_family=AF_INET;
	srvrsock.sin_port=htons(PORT);
	srvrsock.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(bind(nsock,(struct sockaddr *)&srvrsock,sizeof(srvrsock))<0)
		printf("\nBind unsuccessful");
	else
		printf("\nBind successful");
		//printf("\nError!");
	if(listen(nsock,5)<0)
		printf("\nListen unsuccessful");
	else	
		printf("\nListen successful");
	addr_size=sizeof(csock);
	csock=accept(csock,(struct sockaddr *)&csckt,&addr_size);
	if(accept<0)
		printf("\nAccept unsuccessful");
	else 
		printf("\nAccept successful");
		
	//sleep(5);
	if(recv(csock,arr,200,0)<0)
		printf("\nReceive unsuccessful");
	else
		printf("\nReceive successful");
	printf("\nThe array received :-\n");
	for(int i=1;i<=arr[0];i++)
		printf("%d\n",arr[i]);
	
	max=arr[1];
	min=arr[1];
	
	for(int i=1;i<=arr[0];i++)
	{
		if(min>arr[i])
			min=arr[i];
		if (max<arr[i])
			max=arr[i];
		avg+=arr[i];
	}
	avg=avg/arr[0];
	printf("\nMax = %d",max);
	printf("\nMin = %d",min);
	printf("\nAverage = %f",avg);
	close(nsock);
	
}
