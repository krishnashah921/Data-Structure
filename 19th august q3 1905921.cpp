#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	int exp;
	struct node *next;
};
void create(struct node **start,int data1,int expp);
void display(struct node **start);
void addsorted(struct node **start1,struct node **start2,struct node **start3);
void merge(struct node **start1,struct node **start2);
void addunsorted(struct node **start1);
int main()
{
	int data1,expp;
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
	int ch;
	while (1)
	{
		printf("1.Add data in first polynomial\n");
		printf("2.Add data in second polynomial\n");
		printf("3.Display the first poly\n");
		printf("4.Display the second poly\n");
		printf("5.Add sorted the first two polynomial\n");
		printf("6.display the result of two polynomial\n");
		printf("7.add the two unsorted two polynomial\n");
		printf("8.display the addition of two unsorted polynomial\n");
		printf("9.stop\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
			printf("enter the data and exponent\n");
			scanf("%d%d",&data1,&expp);
		    create(&start1,data1,expp);
			break;
			case 2:
			printf("enter the data and exponent\n");
			scanf("%d%d",&data1,&expp);
		    create(&start2,data1,expp);
			break;
			case 3:
			display(&start1);
			break;
			case 4:
			display(&start2);
			break;
			case 5:
			addsorted(&start1,&start2,&start3);
			break;
			case 6:
			display(&start3);
			break;
			case 7:
			merge(&start1,&start2);
			addunsorted(&start1);
			break;
			case 8:
			display(&start1);
			break;	
			case 9:
			exit(1);
			default:
			printf("invalid input\n");	
			break;
		}
	}
	
	return 0;
}
void create(struct node **start,int data1,int expp)
{
	struct node *temp,*newnode;
	newnode=(struct node *)malloc (sizeof (struct node));
	newnode->data=data1;
	newnode->exp=expp;
	newnode->next=NULL;
	if (*start==NULL)
	{
		*start=newnode;
	}
	else 
	{
		temp=*start;
		while (temp->next !=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void display(struct node **start)
{
	struct node *temp;
	if (*start ==NULL)
	{
		printf("no record");
	}
	else 
	{
		temp=*start;
		while (temp !=NULL)
		{
			printf("%dx^%d",temp->data,temp->exp);
			if ((temp->data * (-1) )< 0 && temp->next !=NULL)
			{
				printf("+");
			}
			temp=temp->next;
		}
	}
}
void addsorted(struct node **start1,struct node **start2,struct node **start3)
{
	struct node *temp1,*temp2;
	temp1=*start1;
	temp2=*start2;
	while (temp1 !=NULL && temp2!=NULL)
	{
		if (temp1->exp > temp2->exp)
		{
			create(start3,temp1->data,temp1->exp);
			temp1=temp1->next;
		}
		else if (temp1->exp < temp2->exp)
		{
			create(start3,temp2->data,temp2->exp);
			temp2=temp2->next;
		}
		else 
		{
			if (temp1->data + temp2->data !=0)
			{
				create(start3,temp1->data+temp2->data,temp1->exp);
				temp1=temp1->next;
				temp2=temp2->next;
			}
		}
	}
	while (temp1 !=NULL)
	{
		create(start3,temp1->data,temp1->exp);
		temp1=temp1->next;
	}
	while (temp2 !=NULL)
	{
		create(start3,temp2->data,temp2->exp);
		temp2=temp2->next;
	}
}
void merge(struct node **start1,struct node **start2)
{
	struct node *temp1;
	temp1=*start1;
	while (temp1->next !=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=*start2;
	
}
void addunsorted(struct node **start1)
{
	struct node *st1,*st2,*prev;
	int i;
	for (st1=*start1;st1 !=NULL;st1=st1->next)
	{
		prev=st1;
		st2=st1->next;
		while (st2 !=NULL)
		{
			if (st1->exp !=st2->exp)
			{
				prev=st2;
				st2=st2->next;
			}
			else 
			{
				st1->data=st1->data+st2->data;
				st2=st2->next;
			}
		}
	}
}
