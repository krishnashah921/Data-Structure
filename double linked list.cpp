#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
} ;
void *create(struct node **start);
struct node *display(struct node *start);
int main()
{
	struct node *start1=NULL,*start2=NULL;
	int ch=1;
	//for linkedlist 1
	while (ch==1)
	{
		create(&start1);
		printf("do you want to input node again\n(0/1)\n");
	    scanf("%d",&ch);
	}
	ch=1;
	printf("\nEnter the data for linked list 2");
	while (ch==1)
	{
		create(&start2);
		printf("do you want to input node again\n(0/1)\n");
	    scanf("%d",&ch);
	}
	printf("displaying the data1 of list1\n");
	display(start1);
	printf("displaying the data 2 of list 2\n");
	display(start2);
	return 0;
}
void *create(struct node **start)
{
	struct node *newnode,*temp;
	int data1;
	printf("enter the data\n");
	scanf("%d",&data1);
	newnode=(struct node*) malloc (sizeof (struct node));
	newnode->data=data1;
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
struct node *display(struct node *start)
{
	struct node *tmp;
	tmp=start;
	if (start==NULL)
	{
		printf("no record\n");
		//break;
	}
	else
	{
		while (tmp !=NULL)
	{
		printf("%d\n",tmp->data);
		tmp=tmp->next;
	}	
	} 
}
