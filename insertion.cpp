#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
} *start;
void createlist(int n);
void displaylist();
void insertionatend();
int main()
{
	int n;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	createlist(n);
	insertionatend();
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
void insertionatend()
{
	struct node *ptr,*tempnode;
	printf("enter the data \n");
	int data2;
	scanf("%d",&data2);
	ptr=start;
	while (ptr->next!=NULL)
	{
	  //if (ptr->next !=NULL)
	//{
		ptr=ptr->next;
	//}
	//else 
	//break;
	}
	tempnode=(struct node*) malloc (sizeof(struct node));
	tempnode->data=data2;
	tempnode->next=NULL;
	ptr->next=tempnode;
}

