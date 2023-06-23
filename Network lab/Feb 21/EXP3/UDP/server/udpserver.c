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
   char buffer[30];
   char buffer1[30];
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
   recvfrom(sockd,buffer,sizeof(buffer),MSG_WAITALL,(struct sockaddr *)&clientaddr,&len);
   
   printf("Enter msg : ");
   scanf("%s", buffer1);
   
   sendto(sockd,buffer1,sizeof(buffer1),MSG_CONFIRM,(struct sockaddr *)&clientaddr,len);
   recvfrom(sockd,buffer,sizeof(buffer),MSG_WAITALL,(struct sockaddr *)&clientaddr,&len);
   
   printf("Enter msg : ");
   scanf("%s", buffer1);
   
   sendto(sockd,buffer1,sizeof(buffer1),MSG_CONFIRM,(struct sockaddr *)&clientaddr,len);
   return 0;
}
