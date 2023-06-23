#include<stdio.h>
void main()
{
	int arr[10] = {1,2,3,4};
	printf("Size : %d", sizeof(arr)/sizeof(arr[0]));
}
