#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
}; 
void create(struct node **start,struct node **last);
void display(struct node **start);
void insertbefore(struct node **start);
int main()
{
	struct node *start=NULL,*last=NULL;
	int ch=1;
	while (ch==1)
	{
		create(&start,&last);
		printf("do you want to input more data\n");
		scanf("%d",&ch);
	}
	printf("\ndisplaying the double linked list\n");
	display(&start);
	printf("\n");
	insertbefore(&start);
	return 0;
}
void create(struct node **start,struct node **last)
{
	struct node *newnode,*temp=*last;
	newnode=(struct node*)malloc (sizeof(struct node));
	int data1;
	printf("enter the data\n");
	scanf("%d",&data1);
	newnode->data=data1;
	newnode->prev=NULL;
	newnode->next=NULL;
	if (*start==NULL)
	{
		*start=newnode;
		*last=newnode;
	}
	else 
	{
		newnode->prev=*last;
		temp->next=newnode;
		*last=newnode;
	}
}
void display(struct node **start)
{
	struct node *temp=*start;
	while (temp !=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void insertbefore(struct node **start)
{
	printf("enter the value to insert before \n");
	int bef;
	scanf("%d",&bef);
	struct node *temp=*start,*newnode;
	newnode->data=bef;
	while (temp->data!=bef)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=newnode;
	newnode->next=temp->next->next;
	
}
