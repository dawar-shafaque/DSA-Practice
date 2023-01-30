//on of linked list inputing data printing and counting the number of data

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data; 
    struct Node *next; 
} Node;
void create(Node *ptr)
{
    scanf("%d",&ptr->data); 
    if(ptr->data==-999)
        ptr->next=NULL; 
    else 
    {
        ptr->next=(Node *)malloc(sizeof(Node)); 
        create(ptr->next);
    }
}
void print(Node *ptr)
{
    Node *temp;
    for(temp=ptr;temp->next!=NULL;temp=temp->next)
    {
        printf("%d\t",temp->data);
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
int count(Node *ptr)
{
    if(ptr->next==NULL)
        return(0);
    else
        return (1+(count(ptr->next)));
    
}
int main()
{
    Node *head= (Node *)malloc(sizeof(Node));
    printf("Enter the values of linked list\n");
    printf("Enter -999 to stop\n");
    create(head);
    printf("\n"); 
    head= insertatfirst(head,56); 
    //head = insertatindex(head,56,1);
    //head = insertatend(head,56);
    print(head);
    printf("\n"); 
    printf("\nThe number of items in the linked list is %d\n",count(head));

}