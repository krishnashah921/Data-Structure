#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
};
struct node create(struct node **start,struct node **last);
void insertfirst(struct node **start);
void insertlast(struct node **last);
void insertatpos(struct node **start);
void display(struct node **start,struct node **last);
void deleteatpos(struct node **start);
void deleteelement(struct node **start);
void reverse(struct node **start);
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
		printf("5.delete at pos\n");
		printf("6.delete element\n");
		printf("7.exit\n");
		printf("8.insertion at pos\n");
		printf("9.reverse\n");
		scanf("%d",&choice);
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
				display(&start,&last);
				break;
			case 5:
				deleteatpos(&start);
				break;
			case 6:
				deleteelement(&start);
				break;
			case 7:
				exit(1);
				break;
			case 8:
				insertatpos(&start);
				break;
			case 9:
				reverse(&start);
				break;
			default:
				printf("invalid input\n");
		}
	}
	return 0;
}
struct node create(struct node **start,struct node **last)
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
	printf("%d",temp->data);
	newnode->prev=*last;
	temp->next=newnode;
	*last=newnode;
}
void display(struct node **start,struct node **last)
{
	struct node *ptr=*last;
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
	printf("\n");
	while (ptr !=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->prev;
	}
}
void insertatpos(struct node **start)
{
	struct node *newnode,*temp;
	int pos,data1,c=0;
	printf("enter the position and data to be inserted\n");
	scanf("%d%d",&pos,&data1);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data1;
	temp=*start;
	while (c<pos-1)
	{
		c=c+1;
		temp=temp->next;
	}
	newnode->next=temp;
	newnode->prev=temp->prev->next;
	temp->prev->next=newnode;
	temp->prev=newnode;
}
void deleteatpos(struct node **start)
{
	struct node *temp=*start,*ptr;
	int data1;
	printf("enter the data of at which position to be deleted\n");
	scanf("%d",&data1);
	while (temp->data!=data1)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
}
void deleteelement(struct node **start)
{
	struct node *temp=*start;
	int data1;
	printf("enter the data to be deleted\n");
	scanf("%d",&data1);
	while (temp->data !=data1)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	free(temp);
}
void reverse(struct node **start)
{
	struct node *temp,*current=*start;
	while (current !=NULL)
	{
		temp=current->prev;
		current->prev=current->next;
		current->next=temp;
		current=current->prev;
	}
	*start=temp->prev;
}
