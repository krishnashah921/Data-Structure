#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void create(struct node **start);
void display(struct node **start);
void intersectionpoint(struct node **start1,struct node **start2);
int main()
{
	int ch=1;
	struct node *start1=NULL,*start2=NULL;
	while (ch==1)
	{
		create(&start1);
		printf("\ndo you want to insert more (0/1)\n");
		scanf("%d",&ch);
	}
	ch=1;
	while (ch==1)
	{
		create(&start2);
		printf("\ndo you want to insert more (0/1)\n");
		scanf("%d",&ch);
	}
	struct node *temp=start1,*temp2=start2;
	//temp=start;
	while (temp->next!=NULL)
	temp=temp->next;
	printf("\n");
	//temp->next=temp2->next;
	printf("\nDisplaying the list\n");
	display(&start1);
	printf("\n");
	display(&start2);
	printf("\n");
	temp->next=temp2->next->next->next;
	//temp1->next->next=temp2->next->next;
	printf("\nDisplaying the list\n");
	display(&start1);
	printf("\n");
	display(&start2);
	printf("\n");
	printf("\n");
	intersectionpoint(&start1,&start2);
	return 0;
}
void create(struct node **start)
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
		while (temp->next !=NULL)
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
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void intersectionpoint(struct node **start1,struct node **start2)
{
	struct node *temp1=*start1,*temp2=*start2,*ptr=*start2;
	bool k=false;
	int c1=0,c2=0;
	while (temp1 !=NULL)
	{
		c1=c1+1;
		temp1=temp1->next;
	}
	while (temp2 !=NULL)
	{
		c2=c2+1;
		temp2=temp2->next;
	}
	printf("%d%d",c1,c2);
	temp1=*start1;
	temp2=*start2;
	while (temp1 !=NULL)
	{
		temp2=ptr;
		while (temp2 !=NULL)
		{
			if (temp1 ==temp2 )
			{
				printf("%d is intersection point\n",temp1->data);
				k=true;
				return;
			}
			temp2=temp2->next;
			//printf("%d\n",temp1->data);
		}
		temp1=temp1->next;
		//printf("%d\n",temp1->data);
	}
}
