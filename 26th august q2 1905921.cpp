#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next; 
};
struct node  create(struct node **start);
struct node  display(struct node **start);
struct node insertatbeg(struct node **start);
struct node insertatend(struct node **start);
struct node insertanypos(struct node **start);
struct node deleteanypos(struct node **start);
struct node deleteelement(struct node **start);
int main()
{
	int ch;
	struct node *start=NULL;
	while(1)
	{
		printf("Enter your choice\n");
		printf("1.Create\n");
		printf("2.Insert at beginning\n");
		printf("3.Insert at end\n");
		printf("4.Insert at any pos\n");
		printf("5.delete node from any position\n");
		printf("6.delete particular element\n");
		printf("7.display\n");
		printf("8.exit\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				create(&start);
				break;
			case 2:
				insertatbeg(&start);
				break;
			case 3:
				insertatend(&start);
				break;
			case 4:
				insertanypos(&start);
				break;
			case 5:
				deleteanypos(&start);
				break;
			case 6:
				deleteelement(&start);
				break;
			case 7:
				display(&start);
				break;
			case 8:
				exit(1);
				break;
			default:
					printf("invalid choice\n");
		}
	}
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
struct node insertatbeg(struct node **start)
{
	struct node *newnode,*temp;
	int data1;
	newnode=(struct node*)malloc (sizeof(struct node));
	printf("enter the data to be inserted\n");
	scanf("%d",&data1);
	newnode->data=data1;
	newnode->next=temp->next;
	while (temp->next !=*start)
	{
		temp=temp->next;
	}
	*start=newnode;
	temp->next=*start;
}
struct node insertatend(struct node **start)
{
	struct node *newnode,*temp=*start;
	newnode=(struct node*) malloc (sizeof(struct node));
	int data1;
	printf("enter the data to be inserted\n");
	scanf("%d",&data1);
	newnode->data=data1;
	while (temp->next !=*start)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=*start;
}
struct node insertanypos(struct node **start)
{
	struct node *newnode,*temp=*start,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	int pos,data1,c=1;
	printf("enter the pos and data\n");
	scanf("%d%d",&pos,&data1);
	newnode->data=data1;
	while (temp->next !=*start && c<pos-1)
	{
		c=c+1;
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
struct node deleteanypos(struct node **start)
{
	struct node *temp=*start,*del;
	int pos,c=1;
	printf("enter the pos \n");
	scanf("%d",&pos);
	while (temp->next !=*start && c<pos-1)
	{
		c=c+1;
		temp=temp->next;
	}
	del=temp->next;
	temp->next=del->next;
	free(del);
	
}
struct node deleteelement(struct node **start)
{
	struct node *temp,*del;
	temp=*start;
	int data1;
	printf("enter the data to be deleted\n");
	scanf("%d",&data1);
	while (temp->next->data !=data1)
	{
		temp=temp->next;
	}
	del=temp->next;
	temp->next=del->next;
	free(del);
}
