#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
} *start=NULL;
void createlist(int n);
void displaylist(int n);
int main()
{
	int n;
	printf("enter the number of nodes:");
	scanf("%d",&n);
	createlist(n);
	displaylist(n);
	return 0;
}
void createlist(int n)
{
	struct node *newnode,*temp;
	int i,data1;
	start=(struct node*) malloc(sizeof (struct node));
	if (start==NULL || n==0)
	{
		//printf("unable to allocate the memory");
		//exit(0);
	}
	else 
	{
		printf("enter the data to the node 1:");
		scanf("%d",&data1);
		start->data=data1;
		start->next=NULL;
		temp=start;
		for (i=2;i<=n;i++)
		{
			newnode=(struct node*) malloc(sizeof (struct node));
			if (newnode==NULL)
			{
				printf("unable to allocate memory");
				break;
			}
			else 
			{
				printf("enter the data of node %d:",i);
				scanf("%d",&data1);
				newnode->data=data1;
				newnode->next=NULL;
				temp->next=newnode;
				temp=temp->next;
			}
		}
	}
}
void displaylist(int n)
{
	struct node *tmp;
    if(start == NULL || n==0)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = start;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->data);       // prints the data of current node
            tmp = tmp->next;                     // advances the position of current node
        }
    }
}
