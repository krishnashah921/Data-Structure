#include<stdio.h>
typedef int (*pa);
pa input(int ar[5]);
int main()
{
	int arr[5];
	int *ptr;
	ptr=input(arr);
	for (int i=0;i<5;i++)
	{
		printf("%d\t",*(ptr+i));
	}
	return 0;
}
pa input(int ar[5])
{
	int i,j;
	printf("enter the element to be entered\n");
	for (i=0;i<5;i++)
	{
		scanf("%d",&ar[i]);
	}
	return ar;
}
