#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
};
void create(struct node **start,struct node **last);
void display(struct node **display);
int main()
{
	struct node *start=NULL,*last=NULL;
	int ch;
	while (1)
	{
		printf("enter the choice\n");
		printf("1.create\n");
		printf("2.display\n");
		printf("3.exit\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				create(&start,&last);
				break;
			case 2:
				display(&start);
				break;
			case 3:
				exit(1);
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void create(struct node **start,struct node **last)
{
	struct node *newnode,*head=*start,*end=*last;
	newnode=(struct node*)malloc (sizeof(struct node));
	int dat1;
	printf("enter the data\n");
	scanf("%d",&dat1);
	newnode->data=dat1;
	if (*start==NULL)
	{
		*start=*last=newnode;
		newnode->next=*start;
		newnode->prev=*start;
	}
	else
	{
		end->next=newnode;
		newnode->prev=*last;
		newnode->next=*start;
		head->prev=newnode;
		*last=newnode;
	}
}
void display(struct node **start)
{
	struct node *temp=*start;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while (temp!=*start);
	printf("\n");
}

