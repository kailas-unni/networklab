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
	int clientsocket;
	struct sockaddr_in clientaddr;
	int arr[10];
	int size;
	clientsocket=socket(AF_INET,SOCK_STREAM,0);
	memset(&clientaddr,'\0',sizeof(clientaddr));
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(PORT);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(clientsocket,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
	printf("Enter the array size : ");
	scanf("%d", &arr[0]);
	printf("Enter array elements :\n");
	for(int i=1;i<=arr[0];i++)
		scanf("%d", &arr[i]);
	send(clientsocket,arr,40,0);
	/*recv(clientsocket,buffer,1024,0);
	printf("Data recevied: %s\n",buffer);*/
	close(clientsocket);
}
