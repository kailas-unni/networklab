#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 8000

void main()
{
	int newsock;
	struct sockaddr_in clntsock;
	newsock=socket(AF_INET,SOCK_STREAM,0);
	if(newsock==-1)
		printf("Socket creation unsuccessful!");
	memset(&clntsock,'\0',sizeof(clntsock));
	clntsock.sin_family=AF_INET;
	clntsock.sin_port=htons(PORT);
	clntsock.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(connect(newsock,(struct sockaddr *)&clntsock,sizeof(clntsock))<0)
		printf("\nConnect unsuccessful");
	else 
		printf("\nConnect successful");
	
	int max,min,avg,n,arr[50];
	printf("\nEnter size of the array :-\n");
	scanf("%d",&arr[0]);
	//arr[0]=n;
	printf("\nEnter values of the array :-\n");	
	for(int i=1;i<=arr[0];i++)
		scanf("%d",&arr[i]);
	
	
	if(send(newsock,arr,200,0)<0)
		printf("\nSend unsuccessful");
	else
		printf("\nSend successful");
	close(newsock);
}
	
	
