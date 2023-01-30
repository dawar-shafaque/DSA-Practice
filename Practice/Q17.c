//check if array is sorted
#include<stdio.h>
int main()
{
    int n, count=0; 
    printf("enter the size of array"); 
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    } 
    printf("\nThe array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    } 
   /* for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                int temp = a[i];
                    a[i] = a[j];
                    a[j] = a[i];
            }  
        } 
    } */ 
    for(int i=0;i<n;i++)
    {
        if(a[i+1]>a[i])
        {
            count++;
        }
    } 
    if(count==n)
    {
        printf("\nArray is sorted");
    }
    else{
        printf("\nArray is not sorted");

    }
}