#include<stdio.h> 
#include<stdlib.h>
int *fun(int n)
{
    int *p; 
    p=(int*)malloc(n*sizeof(int)); 
    for(int i=0;i<n;i++)
    p[i]=i+1;
    return(p);
} 
int main()
{
    int *p;
    p=fun(5); 
    for(int i=0;i<5;i++)
    printf("%d\n",p[i]);
} 