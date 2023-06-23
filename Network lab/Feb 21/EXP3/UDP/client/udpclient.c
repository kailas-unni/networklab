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
	char buffer1[20];
	char buffer[20]="HI SERVER";
	if(clisockd<0)
   	{
   		printf("Socket not created\n");
   	}
   	struct sockaddr_in servaddr;
   	servaddr.sin_family=AF_INET;
   	servaddr.sin_port=htons(9050);
   	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   	int len=sizeof(servaddr);
   	sendto(clisockd,buffer,sizeof(buffer),MSG_CONFIRM,(struct sockaddr*)&servaddr,len);
   	recvfrom(clisockd,buffer1,sizeof(buffer1),MSG_WAITALL,(struct sockaddr *)&servaddr,&len);
   	printf("%s\n",buffer1);
   	sendto(clisockd,buffer,sizeof(buffer),MSG_CONFIRM,(struct sockaddr*)&servaddr,len);
   	recvfrom(clisockd,buffer1,sizeof(buffer1),MSG_WAITALL,(struct sockaddr *)&servaddr,&len);
   	printf("%s\n",buffer1);
   	close(clisockd);

	return 0;
}
