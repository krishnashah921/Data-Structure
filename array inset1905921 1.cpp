#include<stdio.h>
#include<stdlib.h>
void insertion(int arr[],int n);
void deletion(int arr[],int n);
void searching(int arr[],int n);
void sorting(int arr[],int n);
void reverse(int arr[],int n);
int main()
{
	int *data,num;
	printf("enter the size\n");
	scanf("%d",&num);
	data=(int*)malloc(num*sizeof(int));
	int i;
	printf("enter the value");
	for (i=0;i<num;i++)
	{
		scanf("%d",(data+i));
	}
	printf("enter your choice\n");
	printf("1.insertion\n");
	printf("2.deletion\n");
	printf("3.searching\n");
	printf("4.sorting\n");
	printf("5.reverse of array\n");
	int ch;
	scanf("%d",&ch);
	switch (ch)
	{
		case 1:
			insertion(data,num);
			break;
		case 2:
			deletion(data,num);
				break;
		case 3:
			searching(data,num);
			break;
		case 4:
			sorting(data,num);
			break;
		case 5:
			reverse(data,num);
			break;
		default:
			printf("invalid input");
	}
	return 0;
}
void insertion(int arr[],int n)
{
	printf("enter the position you want to insert");
	int pos,value1,i;
	printf("enter the value  you want to enter in that position");
	scanf("%d%d",&pos,&value1);
	for (i=n+1;i>pos-1;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[pos-1]=value1;
	for (i=0;i<n+1;i++)
	{
		printf("%d\n",arr[i]);
	}
}
void deletion(int arr[],int n)
{
	int i;
	printf("enter the position you want to delete");
	int pos;
	scanf("%d",&pos);
	for (i=pos-1;i<n;i++)
	{
		arr[i]=arr[i+1];
	}
	for (i=0;i<n-1;i++)
	{
		printf("%d",arr[i]);
		printf("\n");
	}
}
void searching(int arr[],int n)
{
	int value,check=0,val;
	int i;
	printf("enter the value to search");
	scanf("%d",&value);
	check=0;
    for (i=0;i<n;i++)
	{
		if (value==arr[i])
		{
			check=1;
			val=i;
		}
	}
	if (check==1)
	{
		printf("The value found at location %d",val);
	}
	else 
	{
		printf("Not found");
	}
}
void sorting(int arr[],int n)
{
	int i,j,temp;
	for (i=0;i<4;i++)
	{
		for (j=0;j<5-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for (i=0;i<5;i++)
	{
		printf("%d\n",arr[i]);
	}

}
void reverse(int arr[],int n)
{
	int temp,i,j=n;
	{
		while (i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
		for (i=0;i<5;i++)
	{
		printf("%d\n",arr[i]);
	}
	}
}
