// WAP to create a circular linked list and print the elements of the list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *last;
}node;
struct node *create(struct node *list, node* head)
{
    /* struct node *M = NULL;
    struct node *N = NULL;
    int num_nodes, i;
    printf("Enter the no. of nodes you want to create");
    scanf("%d", &num_nodes);
    for (i = 0; i < num_nodes; i++)
    {
        if (head == NULL)
        {
            N = (struct node *)malloc(sizeof(struct node));
            printf("\n List is empty");
            printf("\n Enter the value to be kept at 1st node");
            scanf("%d", &N->data);
            // N->next = NULL;
            head = N;
        }
        else
        {
            M = (struct node *)malloc(sizeof(struct node));
            printf("\n Enter the value to be kept in %d node", i + 1);
            scanf("%d", &M->data);
            N->next = M;
            N = M;
        }  

    } */
    /*struct node *last;
    M->next = head;
    last = M;
    struct node *temp; */
    /*for(temp=head; temp!=last; temp=temp->next)
    {
        printf("%d ", temp->data);
    }
        printf("%d ", last->data);
        printf("%d ", last->next->data);*/
    //return head; 

    scanf("%d",&list ->data);

    if(list->data==-999)
        list->next=head;
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
    } while (ptr != head);

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

struct node *insertAtPos(struct node *head, struct node *ptr, int pos)
{
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
        struct node *temp = head;
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2); 
    }
    return head;
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

int main(void)
{

   /* struct node *head = NULL;

    // CREATING n NUMBER OF NODES

    struct node *M = NULL;
    struct node *N = NULL;
    int num_nodes_460, i; */
    node *head=(node *) malloc(sizeof(node));
    printf("Enter the elements of the node enter -999 to exit the entry of elements \n");
    head = create(head,head);

    int choice;
    do
    {

        printf("\nCircular linked List-\n");
        printf("1.linked list before Insersion\n2.Insert a node at beginning\n3.Insert a node at end\n4.Insert a node at any position\n5.Delete a node at beginning\n6.Delete a node at end\n7.Delete a node at any position\n8.Delete a node for a given key\n9.Count the total no. of nodes\n10. Search for an element in the linked list\n11.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            linkedlistTraversal(head);
            break;
        }

        case 2:
        {
            struct node *ptr;
            printf("\nEnter the new node data:");
            ptr = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &ptr->data);
            head = insertAtFirst(head, ptr);
            linkedlistTraversal(head);
            break;
        }

        case 3:
        {
            struct node *ptr;
            printf("\nEnter the new node data:");
            ptr = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &ptr->data);
            head = insertAtEnd(head, ptr);
            linkedlistTraversal(head);
            break;
        }

        case 4:
        {
            struct node *ptr;
            int pos;
            printf("\nEnter position at which node is to be added:");
            scanf("%d", &pos);
            printf("\nEnter the new node data:");
            ptr = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &ptr->data);
            head = insertAtPos(head, ptr, pos);
            linkedlistTraversal(head);
            break;
        }

        case 5:
        {
            head = deletetAtFirst(head);
            linkedlistTraversal(head);
            break;
        }
        case 6:
        {
            head = deletetAtEnd(head);
            linkedlistTraversal(head);
            break;
        }

        case 7:
        {
            int pos;
            printf("\nEnter position at which node is to be deleted:");
            scanf("%d", &pos);
            head = deleteAtPos(head, pos);
            linkedlistTraversal(head);
            break;
        }

        case 8:
        {
            int key;
            printf("\nEnter the key to be deleted:");
            scanf("%d", &key);
            head = deletekey(head, key);
            linkedlistTraversal(head);

            break;
        }
        case 9:
        {
            countNodes(head);
            break;
        }

        case 10:
        {
            int key;
            printf("\nEnter the element you want to search:");
            scanf("%d", &key);
            search(head, key);
            break;
        }
        case 11:
        {
            printf("\nExiting the program\n");
            break;
        }

        default:
            printf("\nInvalid choice\n");
        }
    } while (choice >= 1 && choice <= 10);
}