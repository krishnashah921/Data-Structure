#include<stdio.h>
struct stud
{
    char name[20];
    int roll,m1,m2,m3,m4,m5,total;
    int average;
    
};

struct stud read();
void display(struct stud d[],int a);
void calculate(struct stud c[],int b);

int main()
{
    int i,n;
    printf("Enter the no. of student: ");
    scanf("%d",&n);
    struct stud s[2];
    for(i=0;i<n;i++)
        s[i]=read();
    calculate(s,i);
    display(s,n);
    return 0;
}

struct stud read()
{
    struct stud r;
    printf("Enter the name: ");
    scanf("%s",r.name);
    printf("Enter the roll number: ");
    scanf("%d",&r.roll);
    printf("Enter the marks:\n");
    scanf("%d%d%d%d%d",&r.m1,&r.m2,&r.m3,&r.m4,&r.m5);
    return(r);
}

void display(struct stud d[],int a)
{
    int i;
    for(i=0;i<a;i++)
    {
        printf("Name: %s\n",d[i].name);
        printf("Roll Number: %d\n",d[i].roll);
        printf("Total Marks: %d\n",d[i].total);
        printf("average:%d\n",d[i].average);
    }
}

void calculate(struct stud c[],int b)
{
    int i;
    for(i=0;i<b;i++)
    {
        c[i].total=c[i].m1+c[i].m2+c[i].m3+c[i].m4+c[i].m5;
        c[i].average= c[i].total/5;
    }
}

