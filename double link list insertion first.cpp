#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
} *start=NULL,*last=NULL;
void create();
void display();
void insertfirst();
void insertpos();
void deleteele();
int main()
{
	int ch=1;
	while (ch==1)
	{
		create();
		printf("do you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\ndisplaying the values\n");
	display();
	printf("\n");
	//insertfirst();
	printf("\n");
	//display();
	//insertpos();
	//deleteele();
	//printf("\n");
	//display();
}
void create()
{
	int data1;
	printf("enter the data\n");
	scanf("%d",&data1);
	struct node *newnode;
	newnode=(struct node*) malloc (sizeof(struct node));
	newnode->data=data1;
	newnode->prev=NULL;
	newnode->next=NULL;
	if (start==NULL)
	{
		start=newnode;
		last=newnode;
	}
	else 
	{
		newnode->prev=last;
		last->next=newnode;
		last=newnode;
	}
}
void display()
{
	struct node *ptr;
	ptr=last;
	if (start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		struct node *temp;
		temp=start;
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
void insertfirst()
{
	int data1;
	printf("enter the data to be inserted\n");
	scanf("%d\n",&data1);
	struct node *newnode;
	newnode=(struct node*) malloc (sizeof (struct node));
    newnode->data=data1;
    start->prev=newnode;
    newnode->next=start;
    start=newnode;
}
void insertpos()
{
	struct node *newnode,*temp;
	int pos,data1,c=0;
	printf("enter the position and data to be inserted\n");
	scanf("%d%d",&pos,&data1);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data1;
	temp=start;
	while (c<pos-1)
	{
		c=c+1;
		temp=temp->next;
	}
	newnode->next=temp;
	newnode->prev=temp->prev->next;
	temp->prev->next=newnode;
	temp->prev=newnode;
	/*newnode->prev=temp;
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;*/
}
void deleteele()
{
	struct node *newnode,*temp=start,*del;
	//newnode=(struct node*)malloc (sizeof(struct node));
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
