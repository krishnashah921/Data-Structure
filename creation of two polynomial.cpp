#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	int exp;
	struct node *next;
};
void *create(struct node **start,int data1,int expp);
void *display(struct node **start);
void *add(struct node **start1,struct node **start2,struct node **start3);
int main()
{
	int data1,expp;
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
	int ch=1;
	while (ch==1)
	{
		printf("enter the data to save and exponent \n");
	    scanf("%d%d",&data1,&expp);
		create(&start1,data1,expp);
		printf("do you want to add number(0/1)\n");
		scanf("%d",&ch);
	}
	ch=1;
	printf("\n");
	while (ch==1)
	{
		printf("enter the data to save and exponent \n");
	    scanf("%d%d",&data1,&expp);
		create(&start2,data1,expp);
		printf("do you want to add number(0/1)\n");
		scanf("%d",&ch);
	}
	printf("displaying the data\n");
	display(&start1);
	printf("\n");
	display(&start2);
	printf("\nDisplaying the addition\n");
	add(&start1,&start2,&start3);
	display(&start3);
	return 0;
}
void *create(struct node **start,int data1,int expp)
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
void *display(struct node **start)
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
			temp=temp->next;
		}
	}
}
void *add(struct node **start1,struct node **start2,struct node **start3)
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
