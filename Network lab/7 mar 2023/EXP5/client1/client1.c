#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
void main()
{
	int sockfd;
	struct sockaddr_in skaddr;
	socklen_t addrlen;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0)
		printf("\nsocket error");
	skaddr.sin_family = AF_INET;
	skaddr.sin_port = htons(6000);
	skaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(connect(sockfd,(struct sockaddr*)&skaddr, sizeof(skaddr))<0)
		printf("\nConnecting error");;
	
	int ch,num;
	char str[20];
	float flt;
	printf("Enter string : ");
	scanf("%s", str);
	printf("Enter number : ");
	scanf("%d", &num);
	printf("Enter float  : ");
	scanf("%f", &flt);
	
	send(sockfd,str,20,0);
	send(sockfd,&num,sizeof(int),0);
	send(sockfd,&flt,sizeof(float),0);
	printf("\nSend to server successfully\n");
	
	close(sockfd);
}
