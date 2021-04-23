#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void create(struct node **start,int data1);
void display(struct node **start);
void mergesorted(struct node **start1,struct node **start2,struct node **start3);
int main()
{
	int ch=1,data1;
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
	while (ch==1)
	{
		printf("what do you want to input\n");
		scanf("%d",&data1);
		create(&start1,data1);
		printf("do you want to add node(0/1)\n");
		scanf("%d",&ch);
	}
	ch=1;
	while (ch==1)
	{
		printf("what do you want to input\n");
		scanf("%d",&data1);
		create(&start2,data1);
		printf("do you want to add node(0/1)\n");
		scanf("%d",&ch);
	}
	printf("displaying first list\n");
	display(&start1);
	printf("displaying secong list\n");
	display(&start2);
	mergesorted(&start1,&start2,&start3);
	printf("\n");
	display(&start3);
	return 0;
}
void create(struct node **start,int data1)
{
	struct node *newnode,*temp;
	temp=*start;
	//int data1;
	//printf("enter the data\n");
	//scanf("%d",&data1);
	newnode=(struct node*)malloc (sizeof (struct node));
	newnode->data=data1;
	newnode->next=NULL;
	if (*start==NULL)
	{
		*start=newnode;
	}
	else 
	{
		while (temp->next !=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void display(struct node **start)
{
	struct node *tmp;
	tmp=*start;
	if (*start==NULL)
	{
		printf("no record");
	}
	else 
	{
		while (tmp!=NULL)
		{
			printf("%d\n",tmp->data);
			tmp=tmp->next;
		}
	}
}
void mergesorted(struct node **start1,struct node **start2,struct node **start3)
{
	struct node *tmp1,*tmp2;
	tmp1=*start1;
	tmp2=*start2;
	while (tmp1 !=NULL && tmp2 !=NULL)
	{
		if ((tmp1->data) > (tmp2->data))
		{
			create(start3,tmp1->data);
			tmp1=tmp1->next;
		}
		else if ((tmp2->data) > (tmp1->data))
		{
			create(start3,tmp2->data);
			tmp2=tmp2->next;
		}
		else 
		{
			create(start3,tmp1->data);
			tmp1=tmp1->next;
			tmp2=tmp2->next;
		}
	}
	while (tmp1 !=NULL)
	{
		create(start3,tmp1->data);
		tmp1=tmp1->next;
	}
	while (tmp2 !=NULL)
	{
		create(start3,tmp2->data);
		tmp2=tmp2->next;
	}
}
