#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void create(struct node **start,int data1);
void display(struct node **start);
void swapnodes(struct node **start);
int main()
{
	int data1;
	struct node *start=NULL;
	int ch=1;
	while (ch==1)
	{
		printf("enter the data\n");
		scanf("%d",&data1);
		create(&start,data1);
		printf("\nDo you want to enter more data(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\nDisplaying the list\n");
	display(&start);
	swapnodes(&start);
	printf("\nSwapped node\n");
	display(&start);
	return 0;
}
void create(struct node **start,int data1)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
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
		while (temp !=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		
	}
}
void swapnodes(struct node **start)
{
	struct node *prevx=NULL,*currentx=*start;
	int x,y;
	printf("\nenter the nodes/data to be swap\n");
	scanf("%d%d",&x,&y);
	if (x==y)
	{
		return;
	}
	while (currentx !=NULL && currentx->data !=x)
	{
		prevx=currentx;
		currentx=currentx->next;
	}
	struct node *prevy,*currenty=*start;
	while (currenty !=NULL && currenty->data !=y)
	{
		prevy=currenty;
		currenty=currenty->next;
	}
	if (currentx==NULL || currenty==NULL)
	{
		return;
	}
	if (prevx !=NULL)
	{
		prevx->next=currenty;
	}
	if (prevy !=NULL)
	{
		prevy->next=currentx;
	}
	struct node *temp;
	temp=currentx->next;
	currentx->next=currenty->next;
	currenty->next=temp;
}
