#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next; 
};
struct node  create(struct node **start);
struct node  display(struct node **start);
int main()
{
	struct node *start=NULL;
	int ch=1;
	while (ch==1)
	{
		create(&start);
		printf("do you want to add more\n");
		scanf("%d",&ch);
	}
	printf("displayed\n");
	display(&start);
	return 0;
}
struct node create(struct node **start)
{
	struct node *newnode,*temp=*start;
	newnode=(struct node*)malloc(sizeof(struct node));
	int data1;
	printf("enter the data \n");
	scanf("%d",&data1);
	newnode->data=data1;
	if (*start==NULL)
	{
		*start=newnode;
		newnode->next=*start;
	}
	else 
	{
		temp=*start;
		while (temp->next !=*start)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=*start;
	}
}
struct node display(struct node **start)
{
	struct node *temp;
	temp=*start;
	do
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}while (temp!=*start);
} 

