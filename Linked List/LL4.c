// Creation of linked list inputing data printing and counting the number of data

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; 
    struct Node* next; 
}Node; 
void create(struct Node* ptr)
{
    scanf("%d",&ptr->data);
    if(ptr->data == -999)
    {
        ptr->next= NULL;
    } 
    else{
        ptr->next=(Node *)malloc(sizeof(Node));
        create(ptr->next);
    }
} 
void traversal(struct Node *ptr)
{
    int i=1;
    while(ptr->data != -999)
    {
        printf("Element %d is: %d\n",i,ptr->data); 
        ptr=ptr->next;
        i++;
    }
}
void main()
{
    struct Node *head = (Node *)malloc(sizeof(Node)); 
    printf("Enter the elements:\n");
    create(head);
    printf("\n"); 
    traversal(head); 
}