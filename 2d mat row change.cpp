#include<stdio.h>
int main()
{
	int arr[4][4],i,j;
	printf("enter the elemetn\n");
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\ndisplaying\n");
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\noutput\n");
	for (i=0;i<1;i++)
	{
		for (j=0;j<4;j++)
		{
			int temp=arr[0][j];
			arr[0][j]=arr[3][j];
			arr[3][j]=temp;
		}
	}
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
