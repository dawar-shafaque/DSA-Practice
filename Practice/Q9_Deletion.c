#include<stdio.h>
int main()
{
    int i,size,pos,n;
    printf("Enter size\n");
    scanf("%d",&size);
    int a[size],temp[size+1];
    printf("Enter numbers in array\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter index of the element to be deleted\n");
    scanf("%d",&n);
        for(i=n;i<(size-1);i++)
        {
            a[i]=a[i+1];

        }
        

        printf("Array after deleting %d\n",n);
        for(i=0;i<(size-1);i++)
        {
        printf("%d\n",a[i]);
         }
}