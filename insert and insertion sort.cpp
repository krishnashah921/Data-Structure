#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void create(struct node **start);
void insert(struct node **start);
void display(struct node **start);
void insertion(struct node **start);
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
	
	//display(&start);
	printf("\n");
	insertion(&start);
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
void insert(struct node **start)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc (sizeof(struct node));
	int data1;
	printf("enter the data to be inputed\n");
	scanf("%d\n",&data1);
	newnode->data=data1;
	newnode->next=*start;
	*start=newnode;
}
void insertion(struct node **start)
{
	insert(start);
	struct node *temp,*ptr=*start;
	while (ptr->next!=NULL)
	{
		temp=ptr->next;
		while (temp!=NULL)
		{
			if (ptr->data>temp->data)
			{
				int tempp;
				tempp=ptr->data;
				ptr->data=temp->data;
				temp->data=tempp;
			}
			temp=temp->next;
		}
		ptr=ptr->next;
	}
}
