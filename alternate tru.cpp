#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void *create(struct node **start,int data1);
void *display(struct node **start);
void *mergealternate(struct node **start1,struct node **start2);
int main()
{
	struct node *start1=NULL,*start2=NULL;
	int ch=1,data1;
	while (ch==1)
	{
		printf("enter the data\n");
	    scanf("%d",&data1);
		create(&start1,data1);
		printf("do you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\n");
	ch=1;
	while (ch==1)
	{
		printf("enter the data\n");
	    scanf("%d",&data1);
		create(&start2,data1);
		printf("do you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("displaying the data\n");
	display(&start1);
	printf("\n");
	display(&start2);
	mergealternate(&start1,&start2);
	printf("displaying the data\n");
	display(&start2);
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
void *mergealternate(struct node **start1,struct node **start2)
{
struct node *first,*second;
	struct node *temp1,*temp2;
	first=*start1;
	second=*start2;
	while (first !=NULL && second !=NULL)
	{
		temp1=first->next;
		temp2=second->next;
		second->next=temp1;
		first->next=second;
		first=temp1;
		second=temp2;
	}
	*start2=second;
}
