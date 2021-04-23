#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct header{
	int dataa;
	struct node *next;
};

struct header *first=NULL;

void create(struct node **start);
void display(struct node **start);
int main()
{
    struct header  *head=NULL;
    
    first=(struct header*)malloc(sizeof(struct header));
    head=first;
	int ch=1;
	struct node *start=NULL;
	while (ch==1)
	{
	    first->dataa++;
	    create(&start);
		
		printf("do you want to repeat\n");
		scanf("%d",&ch);
	}

	printf("\ndisplayign\n");
	display(&start);
	return 0;
}
void create(struct node **start)
{
	struct node *newnode,*temp;
	
	newnode=(struct node*)malloc(sizeof(struct node));
	int data1;
	printf("enter teh data\n");
	scanf("%d",&data1);
	newnode->data=data1;
	newnode->next=NULL;
	if (*start==NULL)
	{
	    
	    first->next=newnode;
	    
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
	struct node *ptr=*start;
	printf("total nodes is %d\n",first->dataa);
	while (ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

