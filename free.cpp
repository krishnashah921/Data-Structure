#include<stdio.h>
int main()
{
	int r,c,i;
	printf("enter the row and column\n");
	scanf("%d%d",&r,&c);
	int arr[r][c],j;
	for (i=0;i<r;i++)
	{
		for ( j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\ndisplaying the mat\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\noutput is \n");
	int ro=0,co=c;
	for (i=0;i<r/2;i++)
	{
		for (j=0;j<c;j++)
		{
			int temp=arr[j][i];
			arr[j][i]=arr[j][co-i-1];
			arr[j][co-i-1]=temp;
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
	return 0;
	
}
