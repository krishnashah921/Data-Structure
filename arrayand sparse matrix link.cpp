#include<stdio.h>
#include<stdlib.h>
struct node {
	int data,row,column;
	struct node *next;
}*start=NULL;
typedef int (*pa)[4];

pa para(int ar[4][4]);
void display();
void createsparse();
void createnode(int row,int col,int value);
int main()
{
createsparse();
printf("\ndisplaying the data\n");
display();
return 0;
}
pa para(int ar[4][4])
{
	printf("enter the value\n");
int i,j;
for (i=0;i<4;i++)
{
for (j=0;j<4;j++)
{
scanf("%d",&ar[i][j]);
}
}
printf("\n");
for (i=0;i<4;i++)
{
for (j=0;j<4;j++)
{
printf("%d\t",ar[i][j]);
}
printf("\n");
}
return ar;
}
void createsparse()
{
	int arr[4][4];
    int (*ptr)[4];
    ptr=para(arr);
	int i,j;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->row=0;
    newnode->column=0;
    newnode->data=0;
    newnode->next=NULL;
    start=newnode;
     for(int m=0;m<4;m++)
    {
        for(int n=0;n<4;n++)
        {
            if(ptr[m][n]!= 0)
            {
                createnode(m,n,ptr[m][n]);
                start->data += 1;
                start->row += 1;
                start->column +=1;
               
            }
        }
    }

}
void createnode(int row,int col,int value)
{
    struct node *temp;

    struct node *newnode=(struct node *)malloc(sizeof(struct node));

    newnode->row=row;
    newnode->column=col;
    newnode->data=value;
    newnode->next=NULL;

    temp=start;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;

}

void display()
{
    struct node *temp=start;
    printf("headnode %d\t%d\t%d",temp->row,temp->column,temp->data);
    
    printf("\n");
    

    temp=start->next;
    while(temp!=NULL)
    {
        printf("\t%d\t",temp->row);
        printf("%d\t",temp->column);
        printf("%d\t",temp->data);
        printf("\n");

        temp=temp->next;
    }
}

