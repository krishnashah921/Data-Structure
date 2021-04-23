//#include<stdio.h>
#include <limits.h> 
#include <stdio.h>
int jump(int arr[],int l,int h);
int main()
{
	int arr[5]={1,3,6,1,9};
	int i,n=5;
	printf("%d",jump(arr,0,n-1));
	return 0;
}
int  jump(int arr[],int l,int h)
{
	 if (h == l) 
        return 0; 
  
    // When nothing is reachable from the given source 
    if (arr[l] == 0) 
        return INT_MAX; 
  
    // Traverse through all the points 
    // reachable from arr[l]. Recursively 
    // get the minimum number of jumps 
    // needed to reach arr[h] from these 
    // reachable points. 
    int min = INT_MAX; 
    for (int i = l + 1; i <= h && i <= l + arr[l]; i++) { 
        int jumps = jump(arr, i, h); 
        if (jumps != INT_MAX && jumps + 1 < min) 
            min = jumps + 1; 
    } 
  
    return min;
}
