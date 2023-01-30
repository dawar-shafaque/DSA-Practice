/*
Write a menu driven program to perform the following operations in a single circular linked 
    list by using suitable user ddefined functions for each case.
    a) Traverse the list
    b) check if the list is empty
    c)  insert a node at a certain position.
    d) delete a node at the certain position.
    e) delete the node for a given key.
    f) count the number of nodes.
    g) search for an element in the linked list.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *nxt;
}node;

void create(node *list,node *head)
{
    scanf("%d",&list ->data);

    if(list->data==-999)
        list->nxt=head;
    else
    {
        list->nxt = (node *)malloc(sizeof(node));
        create(list->nxt,head);
    }
}

node*  transversal(node *list)
    {
        node *first=(node *)malloc(sizeof(node));
        first=list;
        while(list->nxt->nxt!=first)
            list=list->nxt;
        return list;
    }

int count(node *list,int c,node *first)
{
    if(list->nxt!=first)
    {
        c++;
        list=list->nxt;
        count(list,c,first);
    }
    else
        return c;
}

void empty(node *list)
{
    if(count(list,0,list)!=0)
        printf("The list is not empty\n");
    else
        printf("The list is empty\n");
}

node* insert_begin(node *list)
{   
    node *last=transversal(list);  
    node *temp=(node *)malloc(sizeof(node));
        int b;    
            printf("Enter the data you want to enter in the new node ");
            scanf("%d",&b);
        temp->data=b;
        temp->nxt=list;
        
        last->nxt->nxt=temp;
        
        list=temp;
    return list;
}

void insert_mid(node *list,int a)
{
    node *temp=(node *)malloc(sizeof(node));   
        int b;    
            printf("Enter the data you want to enter in the new node ");
            scanf("%d",&b);
        for(int i=0;i<a-2;i++)
            list=list->nxt;
        temp->data=b;
        temp->nxt=list->nxt;
        list->nxt=temp;
}

void insert_end(node *list)
{
    node *last=transversal(list);
    node *temp=(node *)malloc(sizeof(node));   
        int b;    
            printf("Enter the data you want to enter in the new node ");
            scanf("%d",&b);
        temp->data=b;
        temp->nxt=last->nxt;
        last->nxt=temp;
}

node* delete_begin(node *list)
{
    
    node *temp=(node *)malloc(sizeof(node));
    node *last=transversal(list);
    temp=list->nxt;
    free(list);
    list=temp;
    last->nxt->nxt=list;
    return list;
}   
void delete_mid(node *list,int a)
{
    
    node *temp=(node *)malloc(sizeof(node));
        for(int i=0;i<a-2;i++)
            list=list->nxt;
        temp=list->nxt;
    list->nxt=temp->nxt;
        free(temp);
}

void delete_end(node *list)
{
    node *last=transversal(list);
        while(list->nxt!=last)
            list=list->nxt;
    list->nxt=last->nxt;
    free(last);
}

void deletekey(node *list,int dat)
{
    node *temp=(node *)malloc(sizeof(node));
    for(temp=list;temp->nxt->data!=dat;temp=temp->nxt);
    list=temp;
    temp=list->nxt;
    list->nxt=list->nxt->nxt;
    free(temp);
}

void search(node *list,int dat)
{
    int c=0;
    node *first=list;
    while(list->nxt!=first)
    {
        if(list->data==dat)
            c++;
        list=list->nxt;
    }

    if(c>0)
        printf("The element entered is found in the list\n");
    else   
        printf("The element entered is not found in the list\n");
}

void display(node *list,node* first)
{
    if(list->nxt->nxt!=first)
    {
        printf("%d \n",list->data);
        list=list->nxt;
        display(list,first);
    }
    else
    {
        printf("%d\n",list->data);
        printf("%d\n",first->data);
    }
}
void main()
{
    node *head=(node *) malloc(sizeof(node));
    printf("Enter the elements of the node enter -999 to exit the entry of elements \n");
    create(head,head);
    printf("1.Transversal \n");
    printf("2.Check if list is empty \n");
    printf("3.Insert the node at beginnig \n ");
    printf("4.Insert the node at given position \n ");
    printf("5.Insert the node at end \n ");
    printf("6.Delete the node at begining \n");
    printf("7.Delete the node at given position \n");
    printf("8.Delete the node at end \n");
    printf("9.Delete the node for a given key \n");
    printf("10.Count the number of nodes \n");
    printf("11.Search an element \n");
    char ch;
    printf("Enter y each time you want to use the menu ");
    scanf(" %c",&ch);
    int c;
    int a,b;
    node *temp=(node *)malloc(sizeof(node));
    while(ch=='y')
    {
    printf("Enter the character for you given choice \n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            temp=transversal(head);
            printf("After transversal the value of last node is %d \n",temp->data);
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;

        case 2:
            printf("The number of nodes is the list %d \n",count(head,0,head));
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;

        case 3:
            head=insert_begin(head);
            
            printf("After insertion the new linked list is\n");
            display(head,head);

            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;
            
        case 4:
            printf("Enter the position you want to enter the new node ");
            scanf(" %d",&a);
            insert_mid(head,a);
            
            printf("After insertion the new linked list is\n");
            display(head,head);

            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;
     
        case 5:
            insert_end(head);
            printf("After insertion the new linked list is\n");
            display(head,head);

            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;

        case 6:
            head=delete_begin(head);
            
            printf("After deletion the new linked list is\n");
            display(head,head);
            
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;

        case 7:
            printf("Enter the position you want to delete ");
            scanf("%d",&a);
            delete_mid(head,a);
            printf("After deletion the new linked list is\n");
            display(head,head);
            
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;
     
        case 8:
            delete_end(head);
            printf("After deletion the new linked list is\n");
            display(head,head);
            
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;

        case 9:
            printf("Enter the data whose node you want to delete ");
            scanf("%d",&a);
            deletekey(head,a);
            printf("After deletion the new linked list is\n");
            display(head,head);
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;
        case 10:
            printf("The number of nodes in the linked list is %d \n",count(head,0,head));
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;
        case 11:
            printf("Enter the element you want to search ");
            scanf("%d",&a);
            search(head,a);
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
            break;
        default:
            printf("Wrong choice\n");
            printf("Enter y each time you want to use the menu ");
            scanf(" %c",&ch);
    }
    }
}