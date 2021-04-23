#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void *create(struct node **start);
void *display(struct node **start);
void *evenodd(struct node **start);
int main()
{
	int ch=1;
	struct node *start=NULL;
	while (ch==1)
	{
		create(&start);
		printf("do you want to add more data(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\nDisplaying the list\n");
	display(&start);
	printf("\n");
	evenodd(&start);
	printf("displaying the even and odd\n");
//	display(&start);
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
void *evenodd(struct node **start)
{
	struct node *temp;
	int a;
	temp=*start;
	if (start == NULL)
	{
		printf("no records");
	}
	else 
	{
		while (temp !=NULL)
		{
			if (temp->data %2==0)
			{
				printf("%d\n",temp->data);
			}
			temp=temp->next;
		}
	}
	temp=*start;
	while (temp!=NULL)
	{
		if (temp ->data %2==1)
		{
			printf("%d\n",temp->data);
		}
		temp=temp->next;
	}
}
