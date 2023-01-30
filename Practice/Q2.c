#include<stdio.h>
#include<string.h>
struct student {
char name[20];
int rollno;
int marks[5];
int total;
char grade;
};
void sort(struct student s[],int n){
    struct student temp;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[j].rollno>s[j+1].rollno){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }

    }
}
void input(struct student s[],int n){
   
    for (int i = 0; i < n; i++)
    {
        
      printf("Enter the name:\n");
      scanf(" %s[^\n]", &s[i].name);
      printf("Roll no:");
      scanf("%d",&s[i].rollno);
      s[i].total=0;
      for(int j=0;j<5;j++){
        printf("marks out of 100 of Subject %d=",j+1);
        scanf("%d",&s[i].marks[j]);
          s[i].total+=s[i].marks[j];
        }
        if(s[i].total>200){
            s[i].grade='P';
        }
        else{
            s[i].grade='F';
        }
      }  
}
int main(){
    struct student s[55];
    int n; 
    printf("total no. of student:");
    scanf("%d",&n);
    input(s,n);
    sort(s,n);
    for(int i=0;i<n;i++){
        printf("Name: %s \n", s[i].name);
        printf("Roll no: %d \n",s[i].rollno);
        printf("MARKS\n");
        for(int j=0;j<5;j++){
            printf("subject%d=%d\n",j+1,s[i].marks[j]);
        }
        printf("Total marks=%d\n",s[i].total);
        printf("Grade=%c\n",s[i].grade);

    }

}