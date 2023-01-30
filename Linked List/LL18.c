// WAP to create a circular linked list and print the elements of the list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;
struct node *create(struct node *list, node* head)
{
    scanf("%d",&list ->data);

    if(list->data==-999)
    { 
        list->next=head;
    }
    else
    {
        list->next = (node *)malloc(sizeof(node));
        create(list->next,head);
    }

}

void linkedlistTraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr!= head);

    // printf("%d ", last->data);
    printf("%d ", ptr->data);
}

struct node *insertAtFirst(struct node *head, struct node *ptr)
{
    // insert at the beginning in the circular linked list
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *insertAtEnd(struct node *head, struct node *ptr)
{
    // insert at the end in the circular linked list
    struct node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct node *insertAtPos(struct node *head, int pos)
{   
    node *ptr = (node*)malloc(sizeof(node));
    int i;
    if (pos == 1)
    {
        head = insertAtFirst(head, ptr);
        return head;
    }
    struct node *p = head;
    for (i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *deletetAtFirst(struct node *head)
{
    // delete at the beginning in the circular linked list
    struct node *p = head;
    struct node *q;
    while (p->next != head)
    {
        p = p->next;
    }
    q = head;
    head = head->next;
    p->next = head;
    free(q);
    return head;
}

struct node *deletetAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);
    return head;
}

struct node *deleteAtPos(struct node *head, int pos)
{
    if (pos == 1)
    {
        head = deletetAtFirst(head);
        return head;
    }
    else
    {
        /* struct node *temp = head;
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2); */

        struct node *p = head;
        struct node *q = head->next; 
        for(int i=0; i<pos-1;i++)
        {
            p= p->next;
            q= q->next; 
        } 
        p->next = q->next; 
        free(q);
        return head;
    }
}

struct node *deletekey(struct node *head, int key)
{
    struct node *p = head;
    struct node *q = head->next;
    if(p->data==key)
    {
        head = deletetAtFirst(head);
        return head;
    }
    
    while (q->data != key && q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == key)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

void countNodes(struct node *head)
{
    struct node *p = head;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    printf("no of nodes=%d", count);
}

void search(struct node *temp, int key)
{
    int i = 1;
    while (temp->data != key)
    {
        temp = temp->next;
        i++;
    }
    printf("key found at %d position", i);
} 
void display(node *list,node* first)
{
    if(list->next->next!=first)
    {
        printf("%d \n",list->data);
        list=list->next;
        display(list,first);
    }
    else
    {
        printf("%d\n",list->data);
        printf("%d\n",first->data);
    }
}

int main(void)
{
    node *head=(node *) malloc(sizeof(node));
    printf("Enter the elements of the node enter -999 to exit the entry of elements \n");
    head = create(head,head); 
    head = deleteAtPos(head,2);
    linkedlistTraversal(head); 
    //display(head,head);
}