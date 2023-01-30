#include <stdio.h>
#include <stdlib.h>
struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct myarray *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize; 
    a->ptr = (int*)malloc(tsize*sizeof(int));
} 
 void setval(struct myarray *a)
{
    for(int i=0; i< a->used_size; i++)
    {   
        int n;
        printf("Enter element %d",i);
        scanf("%d", &n);
        (a->ptr)[i] = n; 
    }
} 
 void show(struct myarray *a)
{
    for(int i=0; i< a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
int main()
{
    struct myarray marks;
    createarray(&marks, 100, 20); 
    setval(&marks);
    show(&marks);
} 
