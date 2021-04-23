#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void *create(struct node **start,int data1);
void *display(struct node **start);
void *reversegroup(struct node **start,int group);
int main()
{
	struct node *start=NULL;
	int ch=1,data1,k=0;
	while (ch==1)
	{
		k=k+1;
		printf("enter the data\n");
	    scanf("%d",&data1);
		create(&start,data1);
		printf("do you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	int group;
	printf("displaying the data\n");
	display(&start);
	printf("enter the number of nodes that you want to group reverse\n");
	scanf("%d\n",&group);
	reversegroup(&start,group);
	printf("\n");
	display(&start);
	return 0;
}
void *create(struct node **start,int data1)
{
	struct node *newnode,*temp;
	newnode=(struct node *) malloc (sizeof (struct node));
	//int data1;
	newnode->data=data1;
	newnode->next=NULL;
	if (*start==NULL)
	{
		*start=newnode;	}
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
	else 
	{
		temp=*start;
		while (temp !=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void  *reversegroup(struct node **start,int group)
{
	struct node *prev=NULL ,*current,*net=NULL,*temp;
	temp=*start;
	current=*start;
	int count=0;
	while (current !=NULL && count<group)
	{
		net=current->next;
		current->next=prev;
		prev=current;
		current=net;
		count=count+1;
	}
	if (net !=NULL)
	{
	   temp->next=reversegroup(&start,group);
	}
	*start=prev;
}
