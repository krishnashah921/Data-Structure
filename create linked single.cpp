#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void create(struct node **start,int data1);
void display(struct node **start);
int main()
{
	int ch=1,data1;
	struct node *start=NULL;
	while (ch==1)
	{
		printf("enter the number to be stored\n");
		scanf("%d",&data1);
		create(&start,data1);
		printf("\ndo you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\ndisplaying the data\n");
	display(&start);
	return 0;
}
void create(struct node **start,int data1)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc (sizeof (struct node));
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
	struct node *temp;
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		temp=*start;
		while (temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
