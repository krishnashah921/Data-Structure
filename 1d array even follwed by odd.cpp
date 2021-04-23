#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r,i,c=0,k=0;
	printf("enter the number of element\n");
	scanf("%d",&r);
	printf("\n");
	bool f=false;
	int *ptr;
	ptr=(int *)malloc (r*sizeof (int ));
	for (int i=0;i<r;i++)
	{
		scanf("%d",&ptr[i]);
	}
	printf("\n");
	for (i=0;i<r;i++)
	{
		if (ptr[i] %2==0 && f==false )
		{
			printf("%d\n",ptr[i]);
	    }
		if (c==r-1)
			{
				k=1;
				i=0;
				f=true;
			}
		c=c+1;
		if (f==true )
		{
			if (ptr[i]%2!=0)
			{
				printf("%d\n",ptr[i]);
			}
		}
	}
	return 0;
	
}
