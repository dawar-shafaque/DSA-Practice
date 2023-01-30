#include <stdio.h>
#include <stdlib.h>
struct poly{
    int coef;
    int exp;
    struct poly *link;
};
int main()
{
    struct poly* HEAD;
    struct poly* M;
    struct poly* N;
    int num_nodes,i,pos,c=1;
    printf("Enter the order of the polynomial:");
    scanf("%d",&num_nodes);
    for(i=0;i<=num_nodes;i++)
    {
     /*if(HEAD==NULL)
     {
        N=(struct poly*)malloc(sizeof(struct poly));
        printf("Enter the power of x of first element:");
        scanf("%d",&N->exp);
        printf("Enter the coefficient:");
        scanf("%d",&N->coef);
        N->link=NULL;
        //HEAD->link=N;
        HEAD=N;
     }*/
     if(HEAD!=NULL)
     {  
        HEAD =(struct poly*)malloc(sizeof(struct poly)); 
        N=(struct poly*)malloc(sizeof(struct poly));
        M=(struct poly*)malloc(sizeof(struct poly));
        printf("Enter the power of x for element %d:",i);
        scanf("%d",&N->exp);
        printf("Enter the coefficient:");
        scanf("%d",&N->coef);
        M->link=NULL;
        N->link=M;
        N=M;
     }    
    }
    struct poly* temp=HEAD;
    while(temp!=NULL)
    {
        printf("%dx^%d+",temp->coef,temp->exp);
        temp=temp->link;
    }
}