#include<stdio.h>
#include<stdlib.h>
//vashishthafcs@kiit.ac.in
typedef struct Node{
    int data;
    struct Node*Next; 
}*New, *Head, *ptr;
int addele(struct Node*New,struct Node*ptr,struct Node*Head){
     New=(struct Node*)malloc(sizeof(struct Node));
         printf("\nEnter the value:");
         scanf("%d",&New->data);
         ptr->Next=New;
         //ptr=ptr->Next;
         ptr=New;
} 
void display(struct Node *ptr)
{   
    struct Node *temp;
    for(temp=ptr;temp->Next!=NULL;temp=temp->Next)
    {
        printf("\t %d",temp->data);
        ptr=ptr->Next;
    } 
}
/*ptr=head;
while(ptr->next!Null){
    ptr=ptr->next;
    }
    ptr->next=new*/
int main(){
    struct  Node *ptr,*Head,*New;
    
    char ch;
    Head=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value:");
    scanf("%d",&New->data); 
    New->Next=NULL;
    printf("\ndo you want to add more type (y/n)...");
    printf("\n");
    scanf("   %c",&ch);
    printf("\n");
    while(ch=='y'){  
        New->Next= (struct Node*)malloc(sizeof(struct Node));
         addele(New,ptr,Head);
        /* New=(struct Node*)malloc(sizeof(struct Node));
         printf("\nEnter the value:");
         scanf("%d",&New->data);
         New->Next=NULL;
         ptr->Next=New;
         //ptr=ptr->Next;
         ptr=New;*/
         
         printf("\nif you want to add more type (y/n): ");
         printf("\n");
         scanf("   %c",&ch);
        

    }
    printf("Display\n");
    display(Head);
}