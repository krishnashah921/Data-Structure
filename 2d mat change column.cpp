#include<stdio.h>
int main()
{
	int r,co;
	printf("enter the row and column respectively\n");
	scanf("%d%d",&r,&co);
	int arr[r][co],i,j;
	printf("enter the element\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<co;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nDisplaying the input  given matrix\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<co;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("output matrix is \n");
	int temp,c=co;
	for (i=0;i<r/2;i++)
	{
		for (j=0;j<co;j++)
		{
			temp=arr[j][i];
			arr[j][i]=arr[j][c-i-1];
			arr[j][c-i-1]=temp;
		}
	}
	for (i=0;i<r;i++)
	{
		for (j=0;j<co;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
