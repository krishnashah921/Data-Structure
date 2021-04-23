#include<stdio.h>
int main()
{
	int arr[10],i;
	printf("enter the value\n");
	for (i=0;i<10;i++)
	{
		scanf("%d\n",&arr[i]);
	}
	int search,ub,lb,mid;
	printf("enter the value to search");
	scanf("\n%d",&search);
	ub=9;
	lb=0;
	int k=0;
	int pos;
	while (lb<ub)
	{
		mid=(lb+ub)/2;
		if (search>arr[mid])
		{
			lb=mid+1;
		}
		else if (search<arr[mid])
		{
			ub=mid-1;
		}
		else
		{
			k=1;
			pos=mid+1;
		}
	}
	if (k==0)
	{
		printf("value not found");
	}
	else 
	{
		printf("value found at %d",pos);
	}
	return 0;
}
