#include<stdio.h>

typedef int (*pa)[4];

pa para(int ar[][4]);


int main()
{
int arr[4][4];
int i,j;
int (*ptr)[4];
printf("enter the number\n");
ptr=para(arr);
for (i=0;i<4;i++)
{
for (j=0;j<4;j++)
{
printf("%d\t",ptr[i][j]);
}
printf("\n");
}
return 0;
}

pa para(int ar[][4])
{
int i,j;
for (i=0;i<4;i++)
{
for (j=0;j<4;j++)
{
scanf("%d",&ar[i][j]);
}
}
return ar;
}
