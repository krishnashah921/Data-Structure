#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
} *start;
void createlist(int n);
void displaylist();
void insertatbeg();
int main()
{
	int n;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	createlist(n);
	insertatbeg();
	printf("displaying the list\n");
	displaylist();
	return 0;
}
void createlist(int n)
{
	struct node *newnode,*temp;
	int data1,i;
	start=(struct node*) malloc (sizeof(struct node));
	if (start==NULL)
	{
		printf("memory can't be allocated");
		exit(0);
	}
	else 
	{
		printf("enter the first value at the node 1:");
		scanf("%d",&data1);
		start->data=data1;
		start->next=NULL;
		temp=start;
	}
	for (i=2;i<=n;i++)
	{
		newnode=(struct node*) malloc (sizeof (struct node));
		if (newnode==NULL)
		{
			printf("memory can't be allocated");
			break;
		}
		else
		{
			printf("enter the first value at the node %d:",i);
			scanf("%d",&data1);
			newnode->data=data1;
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
		}
	}
}
void displaylist()
{
	struct node *tmp;
	if (start==NULL)
	{
		printf("the list is empty");
	}
	else 
	{
		tmp=start;
		while (tmp !=NULL)
		{
			printf("data is %d\n",tmp->data);
			tmp=tmp->next;
		}
	}
}
void insertatbeg()
{
	int data2;
	printf("enter the data to insert");
	scanf("%d",&data2);
	struct node *tmp;
	tmp=(struct node*) malloc (sizeof (struct node));
	tmp->next=start;
	tmp->data=data2;
	start=tmp;
}
