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

struct Node* insertatfirst(struct Node *head, int data)
{
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
} 
struct Node * insertatindex(struct Node *head, int data, int index)
{
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head; 
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        i++;

    } 
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
} 
struct Node* insertatend(struct Node *head, int data)
{
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    } 
    p->next = ptr;
    ptr->next = NULL;

    return head;
} 

struct Node * insertafternode(struct Node *head,struct Node *prevNode, int data)
{
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data; 
    ptr->next = prevNode->next;
    prevNode->next = ptr; 
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
    fourth->next = NULL;
    traversal(head); 
    printf("After insertion\n");
    //head = insertatfirst(head,56);
    //head = insertatindex(head,56,1);
    //head = insertatend(head,56); 
    head = insertafternode(head, second, 45);
    traversal(head);
    return 0;
}