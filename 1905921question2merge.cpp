#include<stdio.h>
void merge(int arr[5],int ar[5]);
int main()
{
	int arr[5],i;
	int ar[5];
	printf("enter the value\n");
	for (i=0;i<5;i++)
	{
	scanf("%d",&arr[i]);	
	}
	printf("enter the value\n");
	for (i=0;i<5;i++)
	{
	scanf("%d",&ar[i]);	
	}
	merge(arr,ar);
	return 0;
}
void merge(int arr[5],int ar[5])
{
	int mer[10],k;
	int i=0;
	int j=0;
	k=0;
	while (i<5 && j<5)
	{
		if (arr[i]<ar[j])
		{
			mer[k]=arr[i];
			i++;
			k++;
		}
		else 
		{
			mer[k]=ar[j];
			j++;
			k++;
		}
	}
	while (i<5)
	{
		mer[k]=arr[i];
		i++;
		k++;
	}
	while (j<5)
	{
		mer[k]=ar[j];
		j++;
		k++;
	}
	printf("out put is\n");
	for(i=0;i<10;i++)
	{
		printf("%d\n",mer[i]);
	}
}
