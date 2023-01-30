/*
WAP using C to Evaluate the Given Polynomial Equation f(x). Note: Order of
polynomial, co-efficient and value of x will be user input.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int n1,n2; 
    printf("Enter the order of the polynomial 1\n");
    scanf("%d",&n1);
    printf("Enter the order of the polynomial 2\n");
    scanf("%d",&n2); 
    int *f = (int *)malloc((100) * sizeof(int));
    int *poly=(int *) malloc((n1+1) * sizeof(int));
    printf("Enter the coefficients of the polynomial 1 \n");
    for(int i=0;i<n1+1;i++)
        scanf("%d",&poly[i]);
    int *poly2= (int*)malloc((n2+1)*sizeof(int)); 
    printf("Enter the coefficients of the polynomial 2 \n");
    for(int i=0;i<n2+1;i++)
        scanf("%d",&poly2[i]);
    printf("The polynomial 1 is \n"); 
    for(int i=0;i<n1;i++)
    {
        printf("%d*x^(%d) + ",poly[i],(n1-i));
    } 
    printf("%d  \n",poly[n1]);
    printf("The polynomial 2 is \n"); 
    for(int i=0;i<n2;i++)
    {
        printf("%d*x^(%d) + ",poly2[i],(n2-i));
    } 
    printf("%d  \n",poly2[n2]);
    int n;
    if(n1>n2){
        n=n1;
    }
    else{
        n=n2;
    }
    printf("\narray addition\n");
    for(int i=n;i>=0;i--){
       f[i]=poly[i]+poly2[i];            
    }
    printf("thus final polynomial is.....\n");
    for(int i=n;i>=0;i--){
        if(i==0)
        printf("%dx^%d",f[i],n-i);
        else{
            printf("%dx^%d + ",f[i],n-i);
        }
    }  
}