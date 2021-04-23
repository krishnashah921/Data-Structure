#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void create(struct node **start);
void display(struct node **start);
void swap(struct node **start);
int main()
{
	int ch;
	struct node *start=NULL;
	printf("enter your choice\n");
	while (1)
	{
		printf("1.create\n");
		printf("2.display\n");
		printf("3.swap\n");
		printf("4.exit\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				create(&start);
				break;
			case 2:
				display(&start);
				break;
			case 3:
				swap(&start);
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("invalid choice\n");
		}
	}
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
	printf("\n");
}
void swap(struct node **start)
{
	struct node *p,*q,*newstart,*temp;
	p=*start;
	newstart=p->next;
	while (1)
	{
		q=p->next;
		temp=q->next;
		q->next=p;
		if (temp==NULL|| temp->next==NULL)
		{
			p->next=temp;
			break;
		}
		p->next=temp->next;
		p=temp;
	}
	*start=newstart;
}
