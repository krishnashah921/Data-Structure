#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
}; 
struct node create(struct node **start,struct node **last);
struct node display(struct node **start);
struct node insertaft(struct node **start);
struct node insertbef(struct node **last);
struct node deleteatpos(struct node **start);
struct node deletebef(struct node **start);
struct node deleteaft(struct node **last);
int main()
{
	struct node *start=NULL,*last=NULL;
	int ch=1;
	while (ch==1)
	{
		create(&start,&last);
		printf("do you want to input more data\n");
		scanf("%d",&ch);
	}
	printf("\ndisplaying the double linked list\n");
	display(&start);
	printf("\n");
	insertaft(&start);
	display(&start);
	printf("\n");
	insertbef(&last);
	printf("\n");
	display(&start);
	printf("\n");
	deleteatpos(&start);
	printf("\n");
	display(&start);
	deletebef(&start);
	printf("\n");
	display(&start);
	printf("\n");
	deleteaft(&last);
	printf("\n");
	display(&start);
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
struct node  display(struct node **start)
{
	struct node *temp=*start;
	while (temp !=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
struct node insertaft(struct node **start)
{
	struct node *newnode;
	int data1,aft;
	printf("enter the data after you want to input\n");
	scanf("%d",&aft);
	printf("\nenterthe data to be inserted\n");
	scanf("%d",&data1);
	newnode=(struct node*)malloc (sizeof(struct node));
	newnode->data=data1;
	struct node *temp=*start;
	while (temp->data!=aft)
	{
		temp=temp->next;
	}
	//printf("\n%d\n",temp->data);
	newnode->prev=temp;
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
}
struct node insertbef(struct node **last)
{
	struct node *newnode ,*temp=*last;
	int bef,data1;
	newnode=(struct node*) malloc (sizeof(struct node));
	printf("enter the data before you want to input\n");
	scanf("%d",&bef);
	printf("\nenterthe data to be inserted\n");
	scanf("%d",&data1);
	newnode->data=data1;
	while (temp->data!=bef)
	{
		temp=temp->prev;
	}
	printf("\n%d\n",temp->data);
	newnode->next=temp;
	newnode->prev=temp->prev;
	temp->prev->next=newnode;
	temp->prev=newnode;
}
struct node deleteatpos(struct node **start)
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
struct node deletebef(struct node **start)
{
	struct node *temp=*start,*ptr;
	int data1;
	printf("enter the data of which before item to be deleted\n");
	scanf("%d",&data1);
	while (temp->next->data!=data1)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
}
struct node deleteaft(struct node **last)
{
	struct node *temp=*last;
	int data1;
	printf("enter the data of which after item to be deleted\n");
	scanf("%d",&data1);
	while (temp->prev->data!=data1)
	{
		temp=temp->prev;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->next;
}
