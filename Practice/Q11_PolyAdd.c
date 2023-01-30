#include<stdio.h>
int main(){
    int p1[55],p2[55],f[110],d1,d2;
    printf("degree of polynomial p1:");
    scanf("%d",&d1);
    printf("degree of polynomial p2:");
    scanf("%d",&d2);
    printf("polynomial p1:\n");
    for(int i=0;i<=d1;i++){
        printf(" coeff of x for power %d : ",i);
        scanf("%d",&p1[i]);
    }
    printf("\npolynomial p1:");
   
    for(int i=0;i<=d1;i++){
        printf("%dx^%d + ",p1[i],i);
     } 
     printf("\n");
    printf("polynomial p2:\n");
    for(int i=0;i<=d2;i++){
        printf(" coeff of x for power %d : ",i);
        scanf("%d",&p2[i]);
    }
    printf("\npolynomial p2:");
   
    for(int i=0;i<d2;i++){
        
        printf("%dx^%d + ",p2[i],i);
     }
    int n;
    if(d1>d2){
        n=d1;
    }
    else{
        n=d2;
    }
    printf("\narray addition\n");
    for(int i=0;i<=n;i++){
       f[i]=p1[i]+p2[i];            
    }
    printf("thus final polynomial is.....\n");
    for(int i=0;i<=n;i++){
        if(i==n)
        printf("%dx^%d",f[i],i);
        else{
            printf("%dx^%d + ",f[i],i);
        }
    }    



}