#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
};

void create(struct node **start)
{
        struct node *neww,*ptr;
        neww=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&neww->data);
        neww->next=NULL;
        if(*start==NULL)
        {
                *start=neww;
        }
        else
        {
                ptr=*start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=neww;
        }
}
void display(struct node **start)
{
        struct node *ptr;
        if(*start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=*start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->data );
                        ptr=ptr->next ;
                }
        }
}
int count(struct node **start)
{
	
    struct node *temp = *start;
     int count=0;
    while(temp != NULL)
	{
       temp = temp->next;
        count++;
 
    }
    return count;
}
void iatp(struct node **start)
{
	struct node *newnode,*temp;
	int pos,i=1,k;
	k=count(start);
	printf("Enter the position:\n");
	scanf("%d",&pos);
	if(pos>k)
	{
		printf("Invalid position:/n");
	}
	else
	{
		temp=*start;
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
void ibp(struct node **start)
{
	struct node *newnode,*t1,*t2;
	int pos,k,i=1;
	k=count(start);
	printf("Enter the position to insert before it:\n");
	scanf("%d",&pos);
	if(pos>k)
	{
		printf("Invalid position:/n");
	}
	else
	{
		t1=t2=*start;
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
void iafp(struct node **start)
{
	struct node *newnode,*t1,*t2;
	int pos,k,i=1;
	k=count(start);
	printf("Enter the position to insert after it:\n");
	scanf("%d",&pos);
	if(pos>k)
	{
		printf("Invalid position:/n");
	}
	else
	{
		t1=t2=*start;
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
void Delete(struct node **start) 
{ 
 struct node *temp=*start;
 int x;
 printf("enter the value of node to be deleted\n");
 scanf("%d",&x);
 if (*start==NULL)
 {
 	printf("no record to delete");
 }
 else if (temp->data==x) 
 {
 	*start=temp->next;
 	free(temp);
 }
 else
 {
 	struct node *temp2=NULL;
 	while (temp->next->data!=x)
	 {
	 	temp=temp->next;
	 	temp2=temp->next;
	 }
	 temp->next=temp2->next;
	 free(temp2);
 }
}
void search(struct node **start)
{
	struct node *temp;
	int c=0,dat;
	bool k=false;
	temp=*start;
	printf("enter the data to search\n");
	scanf("%d",&dat);
	if (*start==NULL)
	{
		printf("no record\n");
	}
	else if (temp->data==dat)
	{
		k=true;
		c=1;
	}
	else
    {
		while (temp->next !=NULL)
		{
			c=c+1;
			temp=temp->next;
			if (temp->data==dat)
			{
				k=true;
			}
		}
	}
	if (temp->data ==dat)
	{
		k=true;
		c=c+1;
	}
	if (k==true)
	{
		printf("\n%d is found at %d",dat,c);
	}
	else 
	{
		printf("not found");
	}
}
void reverse(struct node **start)
{
	struct node *prev=NULL,*current,*net;
	if (*start==NULL)
	{
		printf("it is empty");
	}
	else 
	{
		current=*start;
		while (current !=NULL)
		{
			net=current->next;
			current->next=prev;
			prev=current;
			current=net;
		}
		*start=prev;
	}
}
int main()      
{
	struct node *start=NULL;
        int choice;
        while(1){
               
                printf("1.Create     \n");
                printf("2.Display    \n");
                printf("3.Insert at pos     \n");
                printf("4.Insert before pos   \n");
                printf("5.Insert after pos   \n");
                printf("6.Deletion   \n");
                printf("7.Searching\n");
                printf("8.Reverse\n");
                printf("9.Stop\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create(&start);
                                        break;
                        case 2:
                                        display(&start);
                                        break;
                        case 3:
									   iatp(&start);
									   break;
						case 4:
									   ibp(&start);
									   break;
						case 5:
									   iafp(&start);
									   break;
						case 6:
									   Delete(&start);
									   break;
						case 7:		   search(&start);
						               break;
						case 8:		   reverse(&start);
						               break; 	       
						case 9:			exit(1);   			   
                        default:
                                        printf(" Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
