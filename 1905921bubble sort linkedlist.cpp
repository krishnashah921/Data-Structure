#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void *create(struct node **start);
void *display(struct node **start);
void *sort(struct node **start,int n);
int main()
{
	int ch=1,k=0;
	struct node *start=NULL;
	while (ch==1)
	{
		k=k+1;
		create(&start);
		printf("do you want to insert more node(0/1)\n");
		scanf("%d",&ch);
	}
	printf("%d\n",k);
	printf("displaying the list \n");
	display(&start);
	//sorting
     sort(&start,k);
	printf("\n");
	display(&start);
	return 0;
}
void *create(struct node **start)
{
	struct node *newnode,*temp;
	newnode=(struct node*) malloc (sizeof(struct node));
	int data1;
	printf("enter the data\n");
	scanf("%d",&data1);
	newnode->data=data1;
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
	struct node *tmp;
	if (*start==NULL)
	{
		printf("no record");
	}
	else 
	{
		tmp=*start;
		while (tmp !=NULL)
		{
			printf("%d\n",tmp->data);
			tmp=tmp->next;
		}
	}
}
void *sort(struct node **start,int n)
{
	struct node *tmp;
	int a,b;
	if (*start ==NULL)
	{
		printf("no record");
	}
	else 
	{
		tmp=*start;
		for (int i=1;i<=n;i++)
		{
			tmp=*start;
			while (tmp->next !=NULL)
			{
				if (tmp->data > tmp->next->data)
				{
					a=tmp->data;
					tmp->data=tmp->next->data;
					tmp->next->data=a;
				}
				tmp=tmp->next;
			}
			//tmp=tmp->next;
		}
	}
}
/*
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void *create(struct node **start);
void *display(struct node **start);
void *sort(struct node **start);
int main()
{
	int ch=1,k=0;
	struct node *start=NULL;
	while (ch==1)
	{
		k=k+1;
		create(&start);
		printf("do you want to insert more node(0/1)\n");
		scanf("%d",&ch);
	}
	printf("displaying the list \n");
	display(&start);
	//sorting
     sort(&start);
	printf("\n");
	display(&start);
	return 0;
}
void *create(struct node **start)
{
	struct node *newnode,*temp;
	newnode=(struct node*) malloc (sizeof(struct node));
	int data1;
	printf("enter the data\n");
	scanf("%d",&data1);
	newnode->data=data1;
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
	struct node *tmp;
	if (*start==NULL)
	{
		printf("no record");
	}
	else 
	{
		tmp=*start;
		while (tmp !=NULL)
		{
			printf("%d\n",tmp->data);
			tmp=tmp->next;
		}
	}
}
void *sort(struct node **start)
{
	struct node *tmp;
	int a,b;
	if (*start ==NULL)
	{
		printf("no record");
	}
	else 
	{
		tmp=*start;
		while (tmp !=NULL)
		{
			tmp=*start;
			while (tmp->next !=NULL)
			{
				if (tmp->data > tmp->next->data)
				{
					a=tmp->data;
					tmp->data=tmp->next->data;
					tmp->next->data=a;
				}
				tmp=tmp->next;
			}
			tmp=tmp->next;
		}
	}
}*/
