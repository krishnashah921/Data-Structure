#include<stdio.h>
#include<stdlib.h>
struct node {
	int row;
	int col;
	int value;
	struct node *next;
};
//struct node *start3=NULL;
void create(struct node **start,int r,int c,int data);
void display(struct node **start);
void add(struct node **start1,struct node **start2,struct node **start3);
int main()
{
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
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
				create(&start1,i,j,arr[i][j]);
			}
		}
	}
	printf("enter the size of the array\n");
	scanf("%d%d",&ro,&co);
	printf("enter the element for second linked list\n");
	int ptr[ro][co];
	for (i=0;i<ro;i++)
	{
		for (j=0;j<co;j++)
		{
			scanf("%d",&ptr[i][j]);
		}
    }
	for (i=0;i<ro;i++)
	{
		for (j=0;j<co;j++)
		{
			if (ptr[i][j]!=0)
			{
				create(&start2,i,j,ptr[i][j]);
			}
		}
	}
	display(&start1);
	printf("\n");
	display(&start2);
	add(&start1,&start2,&start3);
	printf("\n");
    display(&start3);
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
	if  (*start==NULL)
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
void display(struct node **start)
{
	struct node *temp=*start;
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		while (temp!=NULL)
		{
			printf("%d\t%d\t%d",temp->row,temp->col,temp->value);
			printf("\n");
			temp=temp->next;
		}
	}
}
void add(struct node **start1,struct node **start2,struct node **start3)
{
	struct node *temp=*start1,*ptr=*start2;
	while (temp!=NULL && ptr!=NULL)
	{
		if (temp->row<ptr->row)
		{
			create(start3,temp->row,temp->col,temp->value);
			temp=temp->next;
		}
	    if (ptr->row<temp->row)
		{
			create(start3,ptr->row,ptr->col,ptr->value);
			ptr=ptr->next;
		}
	    if (temp->row==ptr->row)
		{
			if (temp->col==ptr->col)
			{
				create(start3,temp->row,temp->col,temp->value+ptr->value);
			}
			else if (temp->col<ptr->col)
			{
				create(start3,temp->row,temp->col,temp->value);
				create(start3,ptr->row,ptr->col,ptr->value);
			}
			else if (ptr->col<temp->col)
			{
				create(start3,ptr->row,ptr->col,ptr->value);
				create(start3,temp->row,temp->col,temp->value);
			}
			temp=temp->next;
			ptr=ptr->next;
				
		}
		//temp=temp->next;
	    //ptr=ptr->next;
	}
	while (temp!=NULL)
	{
		create(start3,temp->row,temp->col,temp->value);
		temp=temp->next;
	}
	while (ptr!=NULL)
	{
		create(start3,ptr->row,ptr->col,ptr->value);
		ptr=ptr->next;
	}
}
