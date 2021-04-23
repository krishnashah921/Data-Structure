#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void create(struct node **start,int data1);
void display(struct node **start);
void detectloop(struct node **start);
int main()
{
	struct node *start=NULL;
	struct node *temp;
	int ch=1,data1,n=0;
	while (ch==1)
	{
		n=n+1;
		printf("enter the data you want to input\n");
		scanf("%d",&data1);
		create(&start,data1);
		printf("\ndo you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	temp=start;
	while (temp->next!=NULL)
	temp=temp->next;
	printf("%d\n",temp->data);
	printf("\n");
	temp->next=start->next;
	printf("\ndisplaying the list\n");
	//display(&start);
	detectloop(&start);
	return 0;
}
void create(struct node **start,int data1)
{
	struct node *newnode,*temp,*tempp=*start;
	newnode=(struct node*) malloc (sizeof(struct node));
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
void display(struct node **start)
{
	struct node *temp;
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		temp=*start;
		while (temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void detectloop(struct node **start)
{
	struct node *slow,*fast;
	slow=fast=*start;
	while (slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if (slow==fast)
		{
			printf("loop");
			exit(1);
		}
	}
}

