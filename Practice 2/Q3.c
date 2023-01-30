//Finding duplicates 
#include<stdio.h>
int main()
{   
    int n;
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
    int dup=0; 
    printf("The new array is:\n");
    for(int i=0;i<n;i++)
    {   
        if(a[i]==a[i+1] && a[i]!=dup)
        {
            printf("%d\n",a[i]); 
            dup = a[i];
            
        } 
        else{
            printf("%d\n",a[i]);
        }
    
    }
}