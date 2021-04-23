#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void create(struct node **start);
void display(struct node **start);
void deleteLast(struct node** start, int x);
int main()
{
	int ch=1,data,x;
	struct node *start=NULL;
	while (1)
	{
		printf("1.create\n");
		printf("2.display\n");
		printf("3.exit\n");
		printf("4.delete last element\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				create(&start);
				break;
			case 2:
				display(&start);
				printf("\n");
				break;
			case 3:
				exit(1);
				break;
			case 4:
				printf("enter the element\n");
				scanf("%d",&x);
				deleteLast(&start,x);
			default:
				printf("wrong choice\n");
				break;
		}
	}
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
void deleteLast(struct node** start, int x)
{
	  struct node  **tmp1 = NULL;
	  struct node *ptr=*start; 
        while(ptr) { 
                if(ptr->data == x) { 
                        *tmp1 = ptr; 
                } 
                *start = ptr->next; 
        } 
        if(*tmp1) { 
                struct node* tmp = *tmp1; 
                *tmp1 = tmp->next; 
                free(tmp); 
        } 
}
