#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
int main()
{
   int sockd=socket(AF_INET,SOCK_DGRAM,0);
   int arr[10];
   if(sockd<0)
   {
   	printf("Socket not created\n");
   }
   struct sockaddr_in seraddr,clientaddr;
   seraddr.sin_family=AF_INET;
   seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   seraddr.sin_port=htons(9050);
   int n= bind(sockd,(struct sockaddr *)&seraddr,sizeof(seraddr));
   if(n<0)
   {
   	printf("bind failed\n");
   }
   int len=sizeof(clientaddr);
   recvfrom(sockd,arr,sizeof(arr),MSG_WAITALL,(struct sockaddr *)&clientaddr,&len);
   
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
   
   return 0;
}
