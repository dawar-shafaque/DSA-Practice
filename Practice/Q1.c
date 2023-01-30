#include<stdio.h> 
#include<stdlib.h> 

int *Add(int *a,int *b)
{
    int *c= (int*)malloc(sizeof(int));
    *c = (*a) + (*b); 
    return c;
}
int main()
{
      /*int c[3][2][2]={{{2,5},{7,9}},{{3,4},{6,1}},{{0,8},{11,13}}},n; 
      printf("%d %d %d %d\n",c,*c,c[0],&c[0][0]); 
      printf("%d\n",*(c[0][0]+1)); 
      int *p;
      p=(int*)malloc(n*sizeof(int)); // for array 
      int *a=(int*)calloc(3,sizeof(int)); 
      int *b=(int*)realloc(p,2*n*sizeof(int));*/ 
      int a=2, b=4; 
      //printf("address of a in main = %d\n",&a);
      int *ptr= Add(&a,&b); 
      printf("sum = %d\n",*ptr); 

} 