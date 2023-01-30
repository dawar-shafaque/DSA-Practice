#include<stdio.h> 
#include<stdlib.h>
int linearsearch(int arr[], int size, int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    } 
    return -1;
}
int main()
{
    int n;
    printf("Enter the size of array"); 
    scanf("%d",&n); 
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int d; 
    printf("Enter the element to be searched");
    scanf("%d",&d);
    //int size = sizeof(a)/sizeof(int);
    int searchindex = linearsearch(a,n,d);
    printf("The element %d was found at index %d\n",d,searchindex);
}