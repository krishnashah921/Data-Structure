#include<stdio.h>
void insert();
void del();
void search();
void sorting();
int create();
int main()
{
	int num,arr[5],i;
	printf("What do you want to do");
	printf("1.Creating the array\n2.Searching the value and display the position\n3.Insertion of value in the array\n4.Deletion of value\n5.Sorting of the value.");
	scanf("%d",&num);
	switch (num)
	{
		case 1:
			printf("Enter the value");
			for (i=0;i<5;i++)
			{
				arr[i]=create();
			}
			//display the array result
			for (i=0;i<5;i++)
			{
				printf("%d\n",arr[i]);
			}
			break;
		case 2:
			printf("Enter the value");
			search();
			break;
		case 3:
			printf("Enter the value");
			insert();
			break;
		case 4:	
		printf("Enter the value");
			del();
			break;
		case 5:	
		printf("Enter the value");
			sorting();
			break;
			default:
				printf("Invalid input");
	}
	return 0;
}
int create()
{
	int i;
	scanf("%d",&i);
	return i;
}
void search()
{
	int value,check=0,val;
	int arr[5];
	int i;
	for (i=0;i<5;i++)
	{
		arr[i]=create();
	}
	printf("enter the value to search");
	scanf("%d",&value);
	check=0;
    for (i=0;i<5;i++)
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
void insert()
{
	int arr[5],i;
	for (i=0;i<5;i++)
	{
		arr[i]=create();
	}
	printf("enter the position you want to insert");
	int pos,value1;
	printf("enter the value you want to enter in that position");
	scanf("%d%d",&pos,&value1);
	for (i=6;i>pos-1;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[pos-1]=value1;
	for (i=0;i<6;i++)
	{
		printf("%d\n",arr[i]);
	}
}
void del()
{
	int arr[5],i;
	for (i=0;i<5;i++)
	{
		arr[i]=create();
	}
	printf("enter the position you want to delete");
	int pos;
	scanf("%d",&pos);
	for (i=pos-1;i<4;i++)
	{
		arr[i]=arr[i+1];
	}
	for (i=0;i<4;i++)
	{
		printf("%d",arr[i]);
		printf("\n");
	}
}
void sorting()
{
	int arr[5],i;
	for (i=0;i<5;i++)
	{
		arr[i]=create();
	}
	int j,temp;
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
