#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;
void traversal(node *ptr)
{
   int i=1; 
   while(ptr->data!=-999)
   {
    printf("The element %d is %d\n",i,ptr->data);
    ptr = ptr->next; 
    i++; 
   }
}
void create(node *ptr)
{   
    scanf("%d",&ptr->data);
    if(ptr->data==-999)
    { 
        ptr->next=NULL;
    } 
    else
    {
        ptr->next=(node*)malloc(sizeof(node));
        create(ptr->next);
    }
}

void print(node *ptr)
{ 
    node *temp;
    for(temp=ptr;temp->next!=NULL;temp=temp->next)
    {
        printf("%d\t",temp->data);
    }
} 

node *insertatfirst(node *head, int data)
{
    node *ptr = (node*)malloc(sizeof(node)); 
    ptr->data= data;
    ptr->next = head; 
    return ptr;
} 
node *insertatindex(node *head, int data, int index)
{
    node *ptr = (node*)malloc(sizeof(node)); 
    node *p = head; 
    int i=0;
    while(i!=index-1)
    {
        p = p->next; 
        i++; 
    } 
    ptr->data = data; 
    ptr->next = p->next;
    p->next=ptr; 
    return head;
} 
node *insertatend(node *head, int data)
{
    node *ptr = (node*)malloc(sizeof(node)); 
    node *p = head;
    while(p->next!= NULL)
    {
        p = p->next; 
    } 
    ptr->data = data;
    p->next= ptr; 
    ptr->next = NULL;
    return head;
} 

node *deleteatfirst(node *head)
{
    node *ptr = head;
    head = head->next; 
    free(ptr); 
    return head; 
} 

node *deleteatindex(node *head, int index)
{
    node *p = head;
    node *q = head->next; 
    for(int i=0; i<index-1;i++)
    {
        p = p->next;
        q = q->next; 
    } 
    p->next = q->next; 
    free(q);
    return head;
} 
node *deleteatlast(node *head)
{
    node *p = head;
    node *q = head->next; 
    while(q->next!=NULL)
    {
        p = p->next; 
        q = q->next; 
    } 
    p->next = NULL;
    free(q);
    return head;
} 
node *deleteatvalue(node *head, int value)
{
    node *p = head; 
    node *q = head->next; 
    while(q->data==value && q->next!=NULL)
    {
        p=p->next; 
        q=q->next;
    } 
    if(q->data ==value )
    {
         p->next = q->next; 
    }
   
    free(q); 
    return head; 
}
int main()
{ 
    node *head= (node *)malloc(sizeof(node)); 
    printf("The elements are:\n");
    create(head);
    printf("\nTraversal\n");  
    //traversal(head);  
    printf("\n"); 
    //head = insertatfirst(head,50); 
    //head = insertatindex(head,85,2); 
    //head = insertatend(head,45); 
    //head = deleteatfirst(head); 
    //head = deleteatindex(head,2); 
    //head = deleteatlast(head); 
    head = deleteatvalue(head,2);
    printf("\n");
    print(head);
    
}