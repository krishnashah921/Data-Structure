#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void create(struct node **start);
void display(struct node **start);
void pairswap(struct node **start);
int main()
{
	int ch=1;
	struct node *start=NULL;
	while (ch==1)
	{
		create(&start);
		printf("\ndo you want to insert more (0/1)\n");
		scanf("%d",&ch);
	}
	printf("\nDisplaying the list\n");
	display(&start);
	printf("\n");
	pairswap(&start);
	display(&start);
	return 0;
}
void create(struct node **start)
{
	struct node *newnode,*temp;
	newnode=(struct node*) malloc (sizeof(struct node));
	int data1;
	printf("enter the data\n");
	scanf("%d",&data1);
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
	struct node *temp=*start;
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		while (temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void pairswap(struct node **start)
{
	struct node *temp=*start;
	int temp1;
	while (temp!=NULL && temp->next!=NULL)
	{
		temp1=temp->data;
		temp->data=temp->next->data;
		temp->next->data=temp1;
		temp=temp->next->next;
	}
}
