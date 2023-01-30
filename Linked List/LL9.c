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

struct Node *deletefirst(struct Node* head)
{
    struct Node *ptr = head; 
    head = head->next; 
    free(ptr);
    return head;
} 
struct Node* deleteatindex(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next;
    for(int i=0; i<index-1; i++)
    {
         p=p->next;
         q=q->next;
    } 
    p->next = q->next; 
    free(q); 
    return head;
} 
struct Node* deletelastnode(struct Node* head)
{
    struct Node* p = head;
    struct Node *q = head->next;
    while(q->next !=NULL) 
    {
        p= p->next;
        q= q->next;
    } 
    p->next = NULL; 
    free(q); 
    return head;
} 
struct Node* deleteatvalue(struct Node* head, int value)
{
    struct Node* p = head;
    struct Node* q = head->next; 
    while(q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next; 
    }
    if(q->data == value)
    {
        p->next = q->next; 
        free(q); 
    } 
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
    //head= insertatfirst(head,56); 
    //head = insertatindex(head,56,3);
    //head = insertatend(head,56);
    //head = insertafternode(head, 2 ,45); 
    //head = deletefirst(head); 
    //head = deleteatindex(head,2);
    //head = deletelastnode(head); 
    head = deleteatvalue(head,6);
    print(head);
    printf("\n"); 
    printf("\nThe number of items in the linked list is %d\n",count(head));

}