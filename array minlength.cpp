#include<stdio.h>
int  aray(int ar[],int n,int value);
int main()
{
	int n,value;
	printf("enter the value to compare the sum\n");
	scanf("%d",&value);
	printf("\nenter the size of array\n");
	scanf("%d",&n);
	int ar[n];
	for (int i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
		printf("\n");
	}
	printf("%d",aray(ar,n,value));
	return 0;
}
int aray(int ar[],int n,int value)
{
	int min=n+1,start=0,end=0,sum;
	while (end<n)
	{
		while (sum<=value && end < n)
		{
			sum=sum+ar[end];
			end=end+1;
		}
		while (sum>value &&start<n)
		{
			if (end-start<min)
			{
				min=end-start;
			}
			sum=sum-ar[start];
			start=start+1;
		}
	}
	return min;
}
