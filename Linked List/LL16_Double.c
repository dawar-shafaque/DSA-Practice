#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create(struct node *head)
{
    struct node *p, *q;
    p=NULL;
    q=NULL;
    int n, i;
    if (head==NULL)
    {
        printf("\nEnter the total number of nodes: ");
        scanf("%d", &n);
        for(i=0;i<n;i++)
        {
            if (head==NULL)
            {
                p=(struct node*)malloc(sizeof(struct node));
                printf("\nEnter the value of : \n");
                printf("\n[%d]Element: ", i);
                scanf("%d", &p->data);
                p->prev=NULL;
                p->next=NULL;
                head=p;
            }
            else
            {
                q=(struct node*)malloc(sizeof(struct node));
                printf("\n[%d]Element: ", i);
                scanf("%d", &q->data);
                q->next=NULL;
                p->next=q;
                q->prev=p;
                p=q;
            }
        }
        printf("\nThe list is created.");
    }
    else
    {
        printf("\nThe list is already created.");
    }
    return head;

}

void forwardtraverse(struct node *head)
{
    int i = 0;
    struct node *p = head;
    while (p != NULL)
    {
        printf("\n[%d]Element: %d", i, p->data);
        p = p->next;
        i++;
    }
}

void backwardtraverse(struct node *head)
{
    int i = 4;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    while (p != NULL)
    {
        printf("\n[%d]Element: %d", i, p->data);
        p = p->prev;
        i--;
    }
}

void empty(struct node *head)
{
    if (head == NULL)
    {
        printf("\nThe list is empty.");
    }
    else
    {
        printf("\nThe list is NOT empty.");
    }
}

struct node *insertatbeg(struct node *head)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the elment you want to insert at the beginning: ");
    scanf("%d", &p->data);
    p->next = head;
    p->prev = NULL;
    head->prev = p;
    return p;
}

struct node *insertatend(struct node *head)
{
    struct node *p = head;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element you want to insert at the end: ");
    scanf("%d", &ptr->data);
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
}

struct node *insertatindex(struct node *head)
{
    int data, index;
    printf("\nEnter the element and the index for insertion: ");
    scanf("%d %d", &data, &index);
    struct node *ptr, *q;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    ptr->data = data;
    q->prev = ptr;
    return head;
}

struct node *deleteatbeg(struct node *head)
{
    struct node *p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}

struct node *deleteatend(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node *deleteatpos(struct node *head)
{
    int i, index;
    struct node *q = head;
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &index);
    if (index == 1)
    {
        head = q->next;
        free(q);
    }
    else
    {
        for (i = 1; i < index; i++)
        {
            q = q->next;
        }
        q->prev->next = q->next;
        free(q);
    }
    return head;
}

struct node *deleteatkey(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    struct node *r=q->next;
    int ele;
    printf("\nEnter the element you want to delete: ");
    scanf("%d", &ele);
    while(ele!=q->data)
    {
        p=p->next;
        q=q->next;
        r=r->next;
    }
    p->next=q->next;
    r->prev=p;
    free(q);
    return head;

}

int main()
{
    struct node *head=NULL;
    
    head=create(head);
    int ch;
    printf("\n\nEnter:\n");
    printf("\n1: To traverse forward.");
    printf("\n2: To traverse backward.");
    printf("\n3: To check if the list is empty.");
    printf("\n4: To insert the node at the beginning.");
    printf("\n5: To insert the node at the end.");
    printf("\n6: To insert the node at any position.");
    printf("\n7: To delete the node at the beginning.");
    printf("\n8: To delete the node at the end.");
    printf("\n9: To delete the node at any position.");
    printf("\n10: To delete a node for a given key.");
    printf("\n0: TO EXIT.");

    while (1)
    {
        printf("\n\nPRESS A BUTTON: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
        {
            printf("\nEXITED\n");
            goto end;
            break;
        }
        case 1:
        {
            forwardtraverse(head);
            break;
        }
        case 2:
        {
            backwardtraverse(head);
            break;
        }
        case 3:
        {
            empty(head);
            break;
        }
        case 4:
        {
            head = insertatbeg(head);
            forwardtraverse(head);
            break;
        }
        case 5:
        {
            head = insertatend(head);
            forwardtraverse(head);
            break;
        }
        case 6:
        {
            head = insertatindex(head);
            forwardtraverse(head);
            break;
        }
        case 7:
        {
            head = deleteatbeg(head);
            forwardtraverse(head);
            break;
        }
        case 8:
        {
            head = deleteatend(head);
            forwardtraverse(head);
            break;
        }
        case 9:
        {
            head = deleteatpos(head);
            forwardtraverse(head);
            break;
        }
        case 10:
        {
            head = deleteatkey(head);
            forwardtraverse(head);
            break;
        }
        default:
        {
            printf("\nINVALID NUMBER.");
            break;
        }
        }
    }

end:
    return 0;
}