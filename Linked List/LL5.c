#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node; 
void create(Node *ptr)
{
    scanf("%d",&ptr->data); 
    if(ptr->data==-999)
        ptr->next=NULL; 
    else 
    {
        ptr->next=(Node *)malloc(sizeof(int)); 
        create(ptr->next);
    }
}
void traversal(struct Node *ptr)
{   
    int i=1;
    while(ptr->data != -999)
    {
        printf("Element %d is %d\n",i,ptr->data); 
        ptr = ptr->next; 
        i++;
    }
} 

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the values\n");
    create(head); 
    printf("\n");
    traversal(head);
    return 0;
}