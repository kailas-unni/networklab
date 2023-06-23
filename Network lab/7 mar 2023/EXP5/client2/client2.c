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
	skaddr.sin_family = AF_INET;
	skaddr.sin_port = htons(6000);
	skaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(sockfd,(struct sockaddr*)&skaddr, sizeof(skaddr));
	
	int ch,num;
	char str[20];
	float flt;
	
	recv(sockfd,&str,20,0);
	recv(sockfd,&num,sizeof(int),0);
	recv(sockfd,&flt,sizeof(float),0);
	printf("\nRecieved from server successfully");

	printf("\nReverse : %s", str);
	printf("\nSquare  : %d", num);
	printf("\nPower   : %.2f\n", flt);
	
	close(sockfd);
}
