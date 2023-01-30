// Creation of linked list inputing data printing and counting the number of data

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data; 
    struct Node *next; 
}Node;
void create(Node *ptr)
{
    scanf("%d",&ptr->data); 
    if(ptr->data==-999)
        ptr->next=NULL; 
    else 
    {
        
        ptr->next  =(Node *)malloc(sizeof(Node)); 
        
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
  /*  while(ptr!=NULL)
    {
        printf("%d",ptr->data); 
        ptr=ptr->next;
    } */
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
    print(head);
    printf("\n");
    printf("\nThe number of items in the linked list is %d\n",count(head));

}