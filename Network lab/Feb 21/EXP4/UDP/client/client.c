#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int clisockd=socket(AF_INET,SOCK_DGRAM,0);
	int arr[10];
	if(clisockd<0)
   	{
   		printf("Socket not created\n");
   	}
   	struct sockaddr_in servaddr;
   	servaddr.sin_family=AF_INET;
   	servaddr.sin_port=htons(9050);
   	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   	int len=sizeof(servaddr);
   	printf("Enter the array size : ");
	scanf("%d", &arr[0]);
	printf("Enter array elements :\n");
	for(int i=1;i<=arr[0];i++)
		scanf("%d", &arr[i]);
   	sendto(clisockd,arr,sizeof(arr),MSG_CONFIRM,(struct sockaddr*)&servaddr,len);
   	
   	close(clisockd);

	return 0;
}
