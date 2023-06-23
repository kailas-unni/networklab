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
	int arr[10];
	int sockfd;
	struct sockaddr_in serveraddr;
	int newsocket;
	struct sockaddr_in newaddr;
	socklen_t addr_size;
	char buffer[20];
	sockfd=socket(PF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
	{
		printf("Colud not create socket");
	}
	memset(&serveraddr,'\0',sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(PORT);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	listen(sockfd,5);
	addr_size=sizeof(newsocket);
	newsocket=accept(sockfd,(struct sockaddr *)&newaddr,&addr_size);
	recv(newsocket,arr,40,0);
	for(int i=0;i<=arr[0];i++)
	{
		printf("Arr[%d] : %d",i,arr[i]);
	}
	int min = arr[1];
	int max = arr[1];
	float avg = 0;
	for(int i=1;i<=arr[0];i++)
	{
		avg = avg+arr[i];
		if(arr[i]<min)
			min = arr[i];
		else if(arr[i]>max)
			max = arr[i];
		else
			continue;
		
	}
	printf("\nSum : %f",avg);
	avg = avg/arr[0];
	printf("\nMin : %d\nMax : %d\nAvg = %f\n",min,max,avg);
	
	close(sockfd);
}
	
