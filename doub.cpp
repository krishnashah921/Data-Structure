#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
//struct node *start=NULL,*last=NULL;
struct node create(struct node *start,struct node *last);
struct node display(struct node *start);
int main()
{
	struct node *start=NULL,*last=NULL;
	int ch=1;
	while (ch==1)
	{
		create(start,last);
		printf("do you want to add more 0/1\n");
		scanf("%d",&ch);
	}
	printf("\nDisplaying the data\n");
	display(start);
	return 0;
}
struct node create(struct node *start,struct node *last)
{
	struct node *newnode;
	int data1;
	newnode=(struct node*) malloc (sizeof (struct node));
	printf("enter the data\n");
	scanf("%d",&data1);
	newnode->data=data1;
	newnode->prev=NULL;
	newnode->next=NULL;
	if (start==NULL)
	{
		start=last=newnode;
	}
	else 
	{
		last->next=newnode;
		newnode->prev=last;
		last=newnode;
	}
}
struct node display(struct node *start)
{
	struct node *temp;
	if (start==NULL)
	{
		printf("no record");
	}
	else 
	{
		temp=start;
		while (temp !=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
