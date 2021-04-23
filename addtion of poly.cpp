#include<stdio.h>
#include<stdlib.h>
struct node{
	int coefficient;
	int exponent;
	struct node *next;
};
void *create(struct node **start,int exp,int data );
void *display(struct node **start);
void *merge(struct node **start1,struct node **start2);
int main()
{
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
	int ch=1,exp,data;
	while (ch==1)
	{
		printf("enter the exponent and coefficient\n");
		scanf("%d%d",&exp,&data);
		create(&start1,exp,data);
		printf("\nDo you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\n");
	ch=1;
	while (ch==1)
	{
		printf("enter the exponent and coefficient\n");
		scanf("%d%d",&exp,&data);
		create(&start2,exp,data);
		printf("\nDo you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\nDisplaying the first polynomial\n");
	display(&start1);
	printf("\nDisplaying the second polynomial\n");
	display(&start2);
	merge(&start1,&start2);
	printf("\n");
	display(&start1);
	return 0;
}
void *create(struct node **start,int exp,int data)
{
	struct node *newnode,*temp;
	newnode=(struct node*) malloc (sizeof (struct node));
	newnode->coefficient=data;
	newnode->exponent=exp;
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
void *display(struct node **start)
{
	struct node *temp;
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		temp=*start;
		while (temp !=NULL)
		{
			printf("%dx^%d\n",temp->coefficient,temp->exponent);
			temp=temp->next;
		}
	}
}
void *merge(struct node **start1,struct node **start2)
{
	struct node *temp1,*temp2;
	temp1=*start1;
	temp2=*start2;
	while (temp1->next !=NULL )
	{
		temp1=temp1->next;
	}
	temp1->next=*start2;
}
