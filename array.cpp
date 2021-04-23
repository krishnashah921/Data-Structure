#include<stdio.h>
int main()
{
	int arr[4][4];
	int i,j,d;
	int c=4;
	printf("enter the element\n");
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\ndisplaying the matriz\n");
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	d=0;
	int temp,n=1,k=0;
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			temp=arr[j][k];
		arr[j][k]=arr[j][c-n];
		arr[j][c-n]=temp;
		
		}
		k=k+1;
		n=n+1;
	}
	printf("\ndisplaying the matriz\n");
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	/*for (i=0;i<4;i++)
	{
		temp=arr[i][1];
		arr[i][1]=arr[i][c-2];
		arr[i][c-2]=temp;
	}
	printf("\ndisplaying the matriz\n");
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}
