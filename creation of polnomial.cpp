#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	int exp;
	struct node *next;
};
void *create(struct node **start);
void *display(struct node **start);
int main()
{
	struct node *start=NULL;
	int ch=1;
	while (ch==1)
	{
		create(&start);
		printf("do you want to add number\n");
		scanf("%d",&ch);
	}
	printf("displaying the data\n");
	display(&start);
	return 0;
}
void *create(struct node **start)
{
	struct node *temp,*newnode;
	newnode=(struct node *)malloc (sizeof (struct node));
	int data1,expp;
	printf("enter the data to save and exponent \n");
	scanf("%d%d",&data1,&expp);
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
