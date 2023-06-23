#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<math.h>
int num;
char str[20];
float flt;

void reverse()
{
	char t;
	for(int i=0;i<strlen(str)/2;i++)
	{
		t = str[i];
		str[i] = str[strlen(str)-1-i];
		str[strlen(str)-i-1] = t;
	}
}

void sq()
{
	num = num*num;
}

void pwr()
{
	flt = pow(flt,1.5);
}

void main()
{
	int sockfd, newfd, newfd2;
	struct sockaddr_in skaddr, newaddr, newaddr1;
	socklen_t addrlen,addrlen1;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0)
		printf("\nsocket error");
	skaddr.sin_family = AF_INET;
	skaddr.sin_port = htons(6000);
	skaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(bind(sockfd,(struct sockaddr*)&skaddr, sizeof(skaddr))<0)
		printf("\nBinding error");
	if(listen(sockfd, 5)<0)
		printf("\nListening error");;
	newfd = accept(sockfd,(struct sockaddr*)&newaddr, &addrlen);
	if(newfd<0)
		printf("\naccept 1 error");
	newfd2 = accept(sockfd,(struct sockaddr*)&newaddr1, &addrlen1);
	if(newfd2<0)
		printf("\naccept 2 error");

	recv(newfd,str,20,0);
	recv(newfd,&num,sizeof(int),0);
	recv(newfd,&flt,sizeof(float),0);
	printf("\nRecieved from client 1 successfully");
	reverse();
	sq();
	pwr();
	
	send(newfd2,str,20,0);
	send(newfd2,&num,sizeof(int),0);
	send(newfd2,&flt,sizeof(float),0);
	printf("\nSend to client 2 successfully\n");
	
	close(sockfd);
	
}
