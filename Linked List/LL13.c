//Insertion and Deletion in a single linked list...

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node; 
void create(struct node *ptr)
{
    scanf("%d",&ptr->data); 
    if(ptr->data==-999)
    {
        ptr->next= NULL;
    }
    else{
        ptr->next=(node*)malloc(sizeof(node)); 
        create(ptr->next);
    }
} 
void print(struct node *ptr)
{
    struct node *temp; 
    for(temp=ptr;temp->next!=NULL;temp=temp->next)
    {   if(temp -> data != -999){
        printf("%d\t",temp->data);

        }
    }
} 
struct node *insertatfirst(struct node *head, int data)
{
    node *ptr =(node*)malloc(sizeof(node)); 
    ptr->data = data;
    ptr->next=head; 
    return ptr;
} 
struct node *insertatindex(struct node* head, int data, int index)
{
    node *ptr =(node*)malloc(sizeof(node)); 
    node *p = head; 
    int i=0;
    while(i!= index-1)
    {
        p = p->next; 
        i++;
    } 
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr; 
    return head;
} 
struct node *insertatend(struct node* head, int data)
{
     node *ptr =(node*)malloc(sizeof(node)); 
     ptr->data=data;
     node *p = head; 
    
     while(p->next!=NULL)
     {
        p = p->next;
     } 
    
     p->next = ptr;
     ptr->next = NULL; 
     return head; 
} 
struct node *deleteatfirst(struct node *head)
{
    struct node *ptr= head;
    head = head->next;
    free(ptr); 
    return head;
} 
struct node *deletelastnode(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next; 
    while(q->next !=NULL)
    {
        p=p->next; 
        q=q->next;
    } 
    p->next = NULL; 
    free(q);
    return head;
} 
struct node *deleteatindex(struct node* head, int index)
{
    struct node *p = head;
    struct node *q = head->next; 
    for(int i=0; i<index-1;i++)
    {
        p= p->next;
        q= q->next; 
    } 
    p->next = q->next; 
    free(q);
    return head;
} 
struct node *deleteatvalue(struct node* head, int value)
{
    struct node *p = head;
    struct node *q = head->next; 
    while(q->data!=value && q->next!=NULL)
    {
        p= p->next;
        q= q->next; 
    } 
    if(q->data==value)
    {
    p->next = q->next; 
    free(q);
    }
    return head;
} 
int count(node *ptr)
{
    if(ptr->next==NULL)
        return(0);
    else
        return (1+(count(ptr->next)));
    
}
void main()
{   
    struct node *head= (node*)malloc(sizeof(node)); 
    printf("The elements are:\n");
    create(head);
    printf("\n"); 
    //head = insertatfirst(head,50); 
    //head = insertatindex(head,80,2); 
    //head = insertatend(head,70); 
    head = deleteatfirst(head); 
    //head = deletelastnode(head); 
    //head = deleteatindex(head,1); 
    //head = deleteatvalue(head,2);
    
    print(head); 
}
