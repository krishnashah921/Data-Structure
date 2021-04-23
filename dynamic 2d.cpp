#include<stdio.h>
#include<stdlib.h>
int main()
{
int *p,n,m,i,j,k,t;
printf("Enter the number of rows of matrix : ");
scanf("%d",&n);
printf("Enter the number of columns of matrix : ");
scanf("%d",&m);
p=(int*)malloc(n*m*sizeof(int));
printf("Enter elements of array :");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",(p+i*m+j));
}
}
return 0;
}
