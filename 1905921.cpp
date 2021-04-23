#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
}*start=NULL;

void create()
{
        struct node *new,*ptr;
        new=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&new->data);
        new->next=NULL;
        if(start==NULL)
        {
                start=new;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=new;
        }
}
void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->data );
                        ptr=ptr->next ;
                }
        }
}
int count()
{
	
    struct node *temp = start;
     int count=0;
    while(temp != NULL)
	{
       temp = temp->next;
        count++;
 
    }
    return count;
}
void iatp()
{
	struct node *newnode,*temp;
	int pos,i=1;
	count();
	printf("Enter the position:\n");
	scanf("%d",&pos);
	if(pos>count)
	{
		printf("Invalid position:/n");
	}
	else
	{
		temp=start;
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d",&newnode->data);
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void ibp()
{
	struct node *newnode,*t1,*t2;
	int pos,i=1;
	count();
	printf("Enter the position to insert before it:\n");
	scanf("%d",&pos);
	if(pos>count)
	{
		printf("Invalid position:/n");
	}
	else
	{
		t1=t2=start;
		while(i<pos)
		{
			t1=t2;
			t2=t1->next;
			i++;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d",&newnode->data);
		t1->next=newnode;
		newnode->next=t2;
	}
}
void iafp()
{
	struct node *newnode,*t1,*t2;
	int pos,i=1;
	count();
	printf("Enter the position to insert after it:\n");
	scanf("%d",&pos);
	if(pos>count)
	{
		printf("Invalid position:/n");
	}
	else
	{
		t1=t2=start;
		while(i<=pos+1)
		{
			t1=t2;
			t2=t1->next;
			i++;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d",&newnode->data);
		t1->next=newnode;
		newnode->next=t2;
	}
}

int main()      
{
        int choice;
        while(1){
               
                printf("1.Create     \n");
                printf("2.Display    \n");
                printf("3.Insert at pos     \n");
                printf("4.Insert before pos   \n");
                printf("5.Insert after pos   \n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
									   iatp();
									   break;
						case 4:
									   ibp();
									   break;
						case 5:
									   iafp();
									   break;
                        default:
                                        printf(" Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
