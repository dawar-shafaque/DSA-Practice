//merging arrays
#include<stdio.h>
int main()
{
    int a[5] = {1,5,3,2,4};
    int b[5] = {6,9,7,8,0}; 
    int c[10]; 
    int j = 0; 
    for(int i=0;i<5;i++)
    {
        c[j] = a[i]; 
        j++;
    } 
    for(int i=0;i<5;i++)
    {
        c[j] = b[i]; 
        j++; 
    } 
    for(int j =0; j<10;j++)
    {
        printf("%d\t",c[j]);
    }
    for(int j=0; j<10; j++)
    {
        if(c[j+1]<c[j])
        {
            int temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
        }
    }
    printf("\nThe merged array is\n");
    for(int j =0; j<10;j++)
    {
        printf("%d\t",c[j]);
    }
}