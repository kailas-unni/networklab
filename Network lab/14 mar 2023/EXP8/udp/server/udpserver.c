#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
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
   	  exit(0);
   }
   printf("\nSocket created successfully");
   struct sockaddr_in seraddr,clientaddr;
   seraddr.sin_family=AF_INET;
   seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   seraddr.sin_port=htons(9050);
   int n= bind(sockd,(struct sockaddr *)&seraddr,sizeof(seraddr));
   if(n<0)
   {
   	  printf("bind failed\n");
   }
   printf("\nBinding successfull");
   int len=sizeof(clientaddr);
   recvfrom(sockd,buffer,sizeof(buffer),0,(struct sockaddr *)&clientaddr,&len);
   printf("\nReqeust recieved : %s", buffer);
   time_t curtime;
   time(&curtime);
   char ti[100];
   strcpy(ti,ctime(&curtime));
   sendto(sockd,ti,sizeof(ti),0,(struct sockaddr *)&clientaddr,len);
   printf("\nRequest resolved");
   return 0;
}
