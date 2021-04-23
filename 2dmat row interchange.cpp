#include<stdio.h>
int main()
{
	int r,c;
	printf("enter the row and column\n");
	scanf("%d%d",&r,&c);
	int arr[r][c],i,j;
	printf("enter the elemetn\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\ndisplaying\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\noutput\n");
	int co=c;
	for (i=0;i<r/2;i++)
	{
		for (j=0;j<c;j++)
		{
			int temp=arr[i][j];
			arr[i][j]=arr[co-1-i][j];
			arr[co-1-i][j]=temp;
		}
	}
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
