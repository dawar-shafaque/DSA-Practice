//pair of elements with sum k
#include<stdio.h>
int main()
{
    int a[10],count=0;
    for(int i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<10; i++)
    {
        printf("%d\t",a[i]);
    } 
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if((a[i]+a[j])==10)
            {
                count++;
            }
        }
    } 
    printf("\nTotal pairs are %d",count);
}