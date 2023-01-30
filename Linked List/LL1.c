#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}; 
void traversal(struct Node *ptr)
{   
    int i=1;
    while(ptr != NULL)
    {
        printf("Element %d is %d\n",i,ptr->data); 
        ptr = ptr->next;
        i++;
    }
} 

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node)); 
    printf("Enter first value\n");
    scanf("%d",&head->data);
    head->next = second; 

    printf("Enter second value\n");
    scanf("%d",&second->data);
    second->next = third; 

    printf("Enter third value\n");
    scanf("%d",&third->data);
    third->next = fourth; 

    printf("Enter fourth value\n");
    scanf("%d",&fourth->data);
    fourth->next = NULL;
    traversal(head);
    return 0;
}