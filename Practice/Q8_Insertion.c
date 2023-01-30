#include<stdio.h>
int main()
{
    int n; 
    printf("Enter the number of elements:\n");
    scanf("%d",&n); 
    int a[n], temp[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    } 
    printf("\n");
    printf("The array is:\n"); 
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    int m,s; 
    printf("\n");
    printf("Enter the position where u want to insert the element");
    scanf("%d",&m); 
    printf("Enter the element to be inserted:\n");
    scanf("%d",&s);
    for(int i=0;i<=n;i++)
    {
        if(i<(m-1))
        {
            temp[i]=a[i];
        } 
        if(i>(m-1))
        {
            temp[i]=a[i-1];
        } 
        if(i==(m-1))
        {
            temp[i]=s;
        } 
    }
        for(int i=0;i<=n;i++)
        {
            printf("%d\t",temp[i]);
        }
    }
