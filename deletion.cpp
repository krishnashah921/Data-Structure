#include<stdio.h>
int main()
{
	int arr[5],i,pos;
	printf("enter the value\n");
	for (i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the value\n");
	scanf("%d",&pos);
	for(i=pos-1;i<4;i++)
	{
		arr[i]=arr[i+1];
	}
	for (i=0;i<4;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
