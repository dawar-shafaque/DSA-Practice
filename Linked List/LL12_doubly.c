#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next; 
    }; 
    create(struct node *head)
    {
        
    }
    int main()
    {
        struct node *n1 = (struct node *)malloc(sizeof(struct node));
        struct node *n2 = (struct node *)malloc(sizeof(struct node)); 
        struct node *n3 = (struct node *)malloc(sizeof(struct node));
        struct node *n4 = (struct node *)malloc(sizeof(struct node)); 
        n1->next= n2;
        n1->prev=NULL; 
    }
    