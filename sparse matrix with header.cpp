#include<stdio.h>
#include<stdlib.h>
struct node {
	int row;
	int col;
	int value;
	struct node *next;
};
void create(struct node **start,int r,int c,int data);
void display(struct node **start);
int main()
{
	struct node *start=NULL,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->row=0;
	newnode->col=0;
	newnode->value=0;
	newnode->next=NULL;
	start=newnode;
	printf("enter the size of the array\n");
	int i,j,ro,co;
	scanf("%d%d",&ro,&co);
	printf("enter the element\n");
	int arr[ro][co];
	for (i=0;i<ro;i++)
	{
		for (j=0;j<co;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for (i=0;i<ro;i++)
	{
		for (j=0;j<co;j++)
		{
			if (arr[i][j]!=0)
			{
				create(&start,i,j,arr[i][j]);
				start->row++;
				start->col++;
				start->value++;
			}
		}
	}
	display(&start);
	return 0;
}
void create(struct node **start,int r,int c,int data)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->row=r;
	newnode->col=c;
	newnode->value=data;
	newnode->next=NULL;
		temp=*start;
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
}
void display(struct node **start)
{
	struct node *temp=*start;
	printf("%d\t%d\t%d\n",temp->row,temp->col,temp->value);	
		temp=temp->next;
		while (temp!=NULL)
		{
			printf("%d\t%d\t%d",temp->row,temp->col,temp->value);
			printf("\n");
			temp=temp->next;
		}
}
