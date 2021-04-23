#include<stdio.h>
typedef int (*pa);
pa input(int ar[7]);
pa display(int ar[7]);
void leftrotate(int arr[],int d,int n);
void leftrotateonebyone(int arr[],int n);
int main()
{
	int arr[7];
	int *ptr;
	int i;
	ptr=input(arr);
	printf("how many value do you want to rotate\n");
	scanf("%d",&i);
	leftrotate(ptr,i,7);
	display(ptr);
	/*for (int i=0;i<5;i++)
	{
		printf("%d\t",*(ptr+i));
	}*/
	return 0;
}
pa input(int ar[7])
{
	int i,j;
	printf("enter the element to be entered\n");
	for (i=0;i<7;i++)
	{
		scanf("%d",&ar[i]);
	}
	return ar;
}
pa display(int ar[7])
{
	for (int i=0;i<7;i++)
	{
		printf("%d\t",ar[i]);
	}
}
void leftrotate(int arr[],int d,int n)
{
	int i;
	for (i=0;i<d;i++)
	{
		leftrotateonebyone(arr,n);
	}
}
void leftrotateonebyone(int arr[],int n)
{
	int i,temp=arr[0];
	for (i=0;i<n-1;i++)
	{
		//arr[i]=arr[i+1];
		//arr[i+1]=temp;
		//temp=arr[i];
		temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;
	}
}
