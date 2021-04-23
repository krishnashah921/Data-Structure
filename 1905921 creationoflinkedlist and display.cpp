#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
} *start=NULL;
void createlist();
void displaylist();
int main()
{
	int num;
	char n;
	printf("what do you do\n");
	printf("1.create the linked list\n2.display the linked list");
	scanf("%d",&num);
	switch (num)
	{
		case 1:
			{
				printf("do you want to create node y/n");
				scanf("%c",&n);
			while (n=='y')
			{
	          createlist();
	        }
	      //  break;
	        }
	     case 2:
		{
			printf("displaying the list\n");
	        displaylist();
	        break;
		}
	}
	return 0;
}
void createlist()
{
	struct node *newnode,*temp;
	int data1,i;
	start=(struct node*) malloc (sizeof(struct node));
		printf("enter the first value at the node :");
		scanf("%d",&data1);
		start->data=data1;
		start->next=NULL;
		temp=start;
		(if temp ==NULL)
		{
			data1=0;
		}
		else
		{
			newnode=(struct node*) malloc (sizeof (struct node));
			//printf("enter the first value at the node :");
			//scanf("%d",&data1);
			newnode->data=data1;
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
		//}
		}
		
}
void displaylist()
{
	struct node *tmp;
	if (start==NULL)
	{
		printf("the list is empty");
	}
	else 
	{
		tmp=start;
		while (tmp !=NULL)
		{
			printf("data is %d\n",tmp->data);
			tmp=tmp->next;
		}
	}
}
