#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void *create(struct node **start);
void *display(struct node **start);
void *evenodd(struct node **start,struct node **start1);
int main()
{
	int ch=1;
	struct node *start=NULL,*start1=NULL;
	while (ch==1)
	{
		create(&start);
		printf("do you want to add more data(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\nDisplaying the list\n");
	display(&start);
	printf("\n");
	evenodd(&start,&start1);
	printf("displaying the even and odd\n");
	display(&start);
	return 0;
}
void *create(struct node **start)
{
	struct node *newnode,*temp;
	newnode=(struct node*) malloc (sizeof (struct node ));
	printf("enter the data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if (*start==NULL)
	{
		*start=newnode;
	}
	else 
	{
		temp=*start;
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void *display(struct node **start)
{
	struct node *temp;
	if (*start==NULL)
	{
		printf("no record");
	}
	temp=*start;
	while (temp !=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	
}
void *evenodd(struct node **start,struct node **start1)
{
	struct node *temp1,*temp,*newnode;
	newnode=(struct node*) malloc (sizeof (struct node));
	temp=*start;
	temp1=*start1;
	if (*start ==NULL)
	{
		printf("list is empty");
	}
	else 
	{
		while (temp !=NULL)
		{
			if (temp->data %2==0)
			{
				newnode->data=temp->data;
			    newnode->next=NULL;
			    temp1=newnode;
			}
			temp=temp->next;
		}
	}
}
