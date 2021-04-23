#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *start=NULL,*last=NULL;
void create();
void display();
int main()
{
	int ch=1;
	while (ch==1)
	{
		create();
		printf("do you want to add more 0/1\n");
		scanf("%d",&ch);
	}
	printf("\nDisplaying the data\n");
	display();
	return 0;
}
void create()
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
		last =newnode;
	}
}
void display()
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
