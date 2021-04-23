#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void create(struct node **start,int data1);
void display(struct node **start);
void sort(struct node **start);
void removedup(struct node **start);
int main()
{
	int ch=1,data1;
	struct node *start=NULL;
	while (ch==1)
	{
		printf("enter the number to be stored\n");
		scanf("%d",&data1);
		create(&start,data1);
		printf("\ndo you want to add more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\ndisplaying the data\n");
	display(&start);
	printf("\n");
	sort(&start);
	display(&start);
	printf("\n");
	removedup(&start);
	display(&start);
	return 0;
}
void create(struct node **start,int data1)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc (sizeof (struct node));
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
	struct node *temp;
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		temp=*start;
		while (temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void sort(struct node **start)
{
	struct node *tmp,*ptr=*start;
	int a,b;
	if (*start ==NULL)
	{
		printf("no record");
	}
	else 
	{
		tmp=*start;
		while (ptr->next!=NULL)
		{
			tmp=ptr->next;
			while (tmp !=NULL)
			{
				if (ptr->data > tmp->data)
				{
					a=ptr->data;
					ptr->data=tmp->data;
					tmp->data=a;
				}
				tmp=tmp->next;
			}
			ptr=ptr->next;
		}
	}
}
void removedup(struct node **start)
{
	
	struct node *current,*nextptr;
	current=*start;
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		while (current->next!=NULL)
		{
			if (current->data==current->next->data)
			{
				nextptr=current->next->next;
				free(current->next);
				current->next=nextptr;
			}
			else 
			{
				current=current->next;
			}
		}
	}
}
