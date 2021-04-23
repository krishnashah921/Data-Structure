#include<stdio.h>
#include<stdlib.h>
struct node {
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
	//struct node *start=NULL;
	while (ch==1)
	{
		create();
		printf("do you want to add some nodes(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\nDisplaying the double circular linked list\n");
	display();
	return 0;
}
void create()
{
	struct node *newnode,*temp=start;
	int data1;
	printf("enter the data you want to input\n");
	scanf("%d",&data1);
	newnode=(struct node*)malloc (sizeof(struct node));
	newnode->data=data1;
	if (start==NULL)
	{
		
		start=last=newnode;
		newnode->next=start;
		newnode->prev=start;
	}
	else 
	{
		last->next=newnode;
		newnode->prev=last;
		newnode->next=start;
		temp->prev=newnode;
		last=newnode;
	}
}
void display()
{
	struct node *temp=start;
	if (start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		do 
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}while (temp !=start);
	}
}
