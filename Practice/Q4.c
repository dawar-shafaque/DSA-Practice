#include<stdio.h> 
#include<stdlib.h>
struct rect 
{
    int length;
    int breadth;
};
int change(struct rect *p,int l)
{
    p->length=l;
} 
int main()
{
    struct rect r={10,5};
    change(&r,20);
    printf("%d\n",r.length);
} 