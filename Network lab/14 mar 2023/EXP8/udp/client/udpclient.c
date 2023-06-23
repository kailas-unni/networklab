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
	char ti[100];
	char buffer[20]="Send time";
	if(clisockd<0)
   	{
   		printf("Socket not created\n");
   	}
   	printf("\nSocket created succefully");
   	struct sockaddr_in servaddr;
   	servaddr.sin_family=AF_INET;
   	servaddr.sin_port=htons(9050);
   	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   	int len=sizeof(servaddr);
   	sendto(clisockd,buffer,sizeof(buffer),0,(struct sockaddr*)&servaddr,len);
   	printf("\nRequested succefully");
   	recvfrom(clisockd,ti,sizeof(ti),0,(struct sockaddr *)&servaddr,&len);
   	printf("\nData recevied succefully\nTime : %s\n",ti);
   	close(clisockd);

	return 0;
}
