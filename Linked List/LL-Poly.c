#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
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
        ptr->next=(Node *)malloc(sizeof(int)); 
        create(ptr->next);
    }
}
void traversal(struct Node *ptr)
{   
    int i=1;
    while(ptr->data != -999)
    {
        printf("Element %d is %d\n",i,ptr->data); 
        ptr = ptr->next; 
        i++;
    }
} 

int main()
{
    struct Node *head; 
    int i,size,p,q,s; 
    printf("Enter the size:\n");
    scanf("%d",&size);
    int p[size],q[size];
    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the size\n");
    int size;
    scanf("%d", &size); 
    for(int i=0;i<size-p; i++)
    {
        printf("Enter the coeff of %dth term",i);
        scanf("%d",&p[i]);
    }
    if(size-p >= size-q)
    {
        size-s = size-p; 

    } 
    else
    size-s = size -q; 
    if(size-p >= size -q)
    {
        for(i=0;i<size-p;i++)
        {
            s[i]=p[i];
        }
    } 
    else{
        for(i=0;i<size-q;i++)
        {
            s[i]=q[i];
        }
    } 
    if(size-p>= size -q)
    {
        for(i=0;i<size-q;i++)
        {
            s[i]=s[i]+q[i]; 
        }
    } 
    else{
        for(i=0;i<size-p;i++)
        {
            s[i]=s[i]+p[i];
        }
    }
    return 0;
}