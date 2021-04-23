#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct headnode
{
    int count;
    struct headnode *next;
};
void create(struct node **start,struct headnode **head,char n)
{
    struct node *temp;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct headnode *first=(struct headnode*)malloc(sizeof(struct headnode));

    if(newnode==NULL)
    {
        printf("Out of Memory Space\n");
        exit(0);
    }
    newnode->data=n;
    newnode->next=NULL;

    if((*start)==NULL)
      {
          first->next=newnode;
          (*start)=newnode;
      }

    else
    {
        temp=(*start);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void traverse(struct node **start,struct headnode **head)
{
    struct headnode *temp=(*head);
    printf("total nodes:- %d \n",(temp->count));
    struct node *t=(*start);
    while(t!=NULL)
    {
        printf("%c ",t->data);
        t=t->next;
    }
    printf("\n");
}
int main()
{
    struct node *start=NULL;struct headnode *head=NULL;

    struct headnode *first=(struct headnode*)malloc(sizeof(struct headnode));

    head=first;
    first->count=0;
    first->next=NULL;


    int c;
    while(1)
    {
     printf("1. create the list\n");
     printf("2. display the list \n");
     printf("3. quit\n");

     printf("enter choice\n");
     scanf("%d",&c);
     switch(c)
     {
        case 1:
            {
                char n;
                printf("enter data\n");
                scanf("%s",&n);
                (first->count)++;
                create(&start,&head,n);
            }
            break;

        case 2:
            {
                traverse(&start,&head);
            }
            break;

        case 3:
            exit(0);

        default:
            printf("invalid choice");
     }
    }
}

