#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(int argc,char const* argr[])
{
 int servdes=socket(AF_INET,SOCK_DGRAM,0);
 char msg[20]="Hello!!";
 struct sockaddr_in serveraddr,clientaddr;
 if(servdes<0)
 {
  printf("Error!!");
 }
 serveraddr.sin_family=AF_INET;
 serveraddr.sin_port=htons(9001);
 serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 
 if((bind(servdes,(struct sockaddr*)&serveraddr,sizeof(serveraddr)))<0)
 {
  printf("Error in binding");
 }
 int len=sizeof(clientaddr);

 //new code begins here.. To get clientaddr and its length recvfrom needs to be used first so that client can send data
 //notice buffer isn't used anywhere else. Just to get clientaddress.
 char buffer[20];
 recvfrom(socket,buffer,sizeof(buffer),0,(struct sockaddr *)&clientaddr,&len);    
 //new code ends here

 sendto(servdes,msg,sizeof(msg),0,(struct sockaddr*)&clientaddr,len);
 //close(servdes);
 return 0;
}
