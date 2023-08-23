#include<stdio.h>
#include<string.h>
main()
{
	char source[20],destination[20];
	printf("enter a string:");
	scanf("%s",&source);
	strcpy(destination,source);
	printf("source string is:%s",source);
	printf("\n the copied string is:%s",destination);
}
