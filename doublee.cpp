#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
} *start=NULL,*last=NULL;
void create();
void display();
int main()
{
	int ch=1;
	while (ch==1)
	{
		create();
		printf("do you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\ndisplaying the values\n");
	display();
}
void create()
{
	int data1;
	printf("enter the data\n");
	scanf("%d",&data1);
	struct node *newnode;
	newnode=(struct node*) malloc (sizeof(struct node));
	newnode->data=data1;
	newnode->prev=NULL;
	newnode->next=NULL;
	if (start==NULL)
	{
		start=newnode;
		last=newnode;
	}
	else 
	{
		newnode->prev=last;
		last->next=newnode;
		last=newnode;
	}
}
void display()
{
	if (start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		struct node *temp;
		temp=start;
		while (temp !=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
