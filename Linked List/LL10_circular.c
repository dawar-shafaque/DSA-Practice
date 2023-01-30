#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data; 
    struct Node *next; 
}Node; 
void traversal(struct Node *head)
{
    
    struct Node* ptr= head; 
    printf("print");
    do{
        printf("element is %d\n",ptr->data); 
        ptr = ptr -> next;
        if(ptr==head)
        break;
    }while(1);
} 

void create(Node *head)
{   
    struct Node* ptr = head; 
    ptr=(Node *)malloc(sizeof(Node)); 
    scanf("%d",&ptr->data);
    while(ptr->data!=-999)
    {   
        scanf("%d",&ptr->data);
      //  printf("%d", ptr->data); 
        ptr = ptr->next;
    } 
    ptr->next= head; 
   
}

/*struct node* print(Node *ptr)
{
    Node *temp; 
    Node *head= (Node *)malloc(sizeof(Node)); 
     ptr = head;
    for(temp=ptr;temp->next!=ptr;temp=temp->next)
    {
        printf("%d\t",temp->data);
    } 
} 
*/
/*int count(Node *ptr)
{
    if(ptr->next==NULL)
        return(0);
    else
        return (1+(count(ptr->next))); 
    
} */
int main()
{
    Node *head= (Node *)malloc(sizeof(Node));
    printf("Enter the values of linked list\n");
    printf("Enter -999 to stop\n");
    create(head);
    printf("printmain"); 
    traversal(head);
    printf("\n");
    //print(head);
    printf("\n"); 
    //printf("\nThe number of items in the linked list is %d\n",count(head));

}