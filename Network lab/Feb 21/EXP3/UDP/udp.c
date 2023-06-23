#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(int argc,char const* argr[])
{
 int clientdes=(AF_INET,SOCK_DGRAM,0);
 char msg[20];
 if(clientdes<0)
 {
  printf("Error in creating socket");
 }
 
 struct sockaddr_in clientaddr;
 clientaddr.sin_family=AF_INET;
 clientaddr.sin_port=htons(9001);
 clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 int len=sizeof(clientaddr);

 //new code begins here.. To send client address to server. Buffer is a pseudo value just to send cient details
 char buffer[20] = "DummyWord";
 sendto(clisockd,buffer,sizeof(buffer),MSG_CONFIRM,(struct sockaddr*)&servaddr,len);
 //new code ends here
 
 recvfrom(clientdes,msg,sizeof(msg),0,(struct sockaddr*)&clientaddr,&len);
 printf("Hi");
 printf("%s\n",msg);
 close(clientdes);
 return 0;
}

