#include<stdio.h>
#include<stdlib.h>
struct node {
	int coefficient;
	int exponent;
	struct node *next;
};
void *create(struct node **start,int coeff,int exp);
void *display(struct node **start);
int main()
{
	int ch=1,coeff,exp;
	struct node *start=NULL;
	while (ch==1)
	{
		printf("enter the coefficient and exponent\n");
		scanf("%d%d",&coeff,&exp);
		//printf("enter the exponent\n");
		//scanf("%d\n" ,&exp);
		create(&start,coeff,exp);
		printf("Do you want to add more polynomial(0/1)\n");
		scanf("%d",&ch);
	}
	printf("displaying the first polynomial entered\n");
	display(&start);
	return 0;
}
void *create (struct node **start,int coeff,int exp)
{
	struct node *temp,*newnode;
	newnode=(struct node *) malloc(sizeof (struct node));
	newnode->coefficient=coeff;
	newnode->exponent=exp;
	newnode->next=NULL;
	if (*start==NULL)
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
			printf("%dx^%d",temp->coefficient,temp->exponent);
			temp=temp->next;
		}
	}
}
