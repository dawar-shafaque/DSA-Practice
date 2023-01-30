#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}; 
void traversal(struct Node *head)
{
    struct Node* ptr = head; 
    do{
        printf("element is %d\n",ptr->data);
        ptr = ptr -> next;
    }while(ptr!=head);
} 
struct Node* insertatfirst(struct Node* head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node)); 
    ptr->data=data; 
    struct Node* p = head ->next; 
    while(p->next !=head)
    {
        p= p->next;
    } 
    p->next=ptr;
    ptr->next = head; 
    head = ptr;
    return head;
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
    fourth->next = head;
    head = insertatfirst(head,80);
    traversal(head); 
    return 0;
}