#include<stdio.h>
int main()
{
	int arr[5],i,pos,val;
	printf("enter the value\n");
	for (i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the value\n enter the position \n");
	scanf("%d%d",&val,&pos);
	for(i=pos-1;i<6;i++)
	{
		arr[i+1]=arr[i];
	}
	arr[pos-1]=val;
	for (i=0;i<6;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
