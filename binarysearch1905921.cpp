#include<stdio.h>
int main()
{
	int arr1[10],i;
	printf("enter the value in array\n");
	for (i=0;i<10;i++)
	{
		scanf("%d",&arr1);
	}
	int search,first,last,mid;
	printf("\nenter the value to search");
	scanf("%d",&search);
	first=0;
	int k=0;
	last=9;
	while(first<last)
	{
		mid=(first+last)/2;
		if (search>arr1[mid])
		{
			first=mid+1;
		}
		else if (search<arr1[mid])
		{
			last=mid-1;
		}
		else
		{
			k=1;
			//printf("%d is found at %d",search,mid+1);
			break;
		}
	}
	if (first>last || k==0)
	{
		printf("not found");
	}
	else 
	{
		printf("%d is found at %d",search,mid+1);
	}
	return 0;
}
