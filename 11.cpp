#include<stdio.h>
#include<stdlib.h>
void create(struct node **start,struct node **last);
void insertfirst(struct node **start);
void insertlast(struct node **last);
int main()
{
	struct node *start=NULL,*last=NULL;
	int choice;
	while (1)
	{
		printf("enter your choice\n");
		printf("1.create the linked list\n");
		printf("2.insert at beginning of  the linked list\n");
		printf("3.insert at last of the linked list\n");
		printf("4.display\n");
		printf("5.exit\n");
		switch (choice)
		{
			case 1:
				create(&start,&last);
				break;
			case 2:
				insertfirst(&start);
				break;
			case 3:
				insertlast(&last);
				break;
			case 4:
				display(&start);
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("invalid input\n");
		}
	}
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
		temp->next=newnode;
		newnode->prev=*last;
		//temp->next=newnode;
		*last=newnode;
	}
}
void insertfirst(struct node **start)
{
	int data1;
	struct node *temp=*start;
	printf("enter the data to be inserted\n");
	scanf("%d\n",&data1);
	struct node *newnode;
	newnode=(struct node*) malloc (sizeof (struct node));
    newnode->data=data1;
    newnode->next=*start;
    temp->prev=newnode;
    *start=newnode;
}
void insertlast(struct node **last)
{
	struct node *newnode,*temp=*last;
	int data1;
	printf("enter the data to be inserted\n");
	scanf("%d",&data1);
	newnode=(struct node*)malloc (sizeof(struct node));
	newnode->data=data1;
	printf("%d",*last->data);
	newnode->prev=*last;
	temp->next=newnode;
	*last=newnode;
}
void display(struct node **start)
{
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		struct node *temp;
		temp=*start;
		while (temp !=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
