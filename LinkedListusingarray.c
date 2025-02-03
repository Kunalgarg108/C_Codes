#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;
void Create(int A[],int n);
void Display1(struct Node *p);
void Display2(struct Node *p);
int main()
{
   int A[]={5,4,3,2,1};
   Create(A,5);
   Display2(first);
   return 0;
}
void Create(int A[],int n){
    struct Node *t;
    struct Node *last;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    last=first;
    first->next=NULL;
    for(i=1;i<n;i++){
       t=(struct Node*)malloc(sizeof(struct Node));
       t->data=A[i];
       t->next=NULL;
       last->next=t;
       last=t;
    }
}
//Iterative Version
void Display1(struct Node *p){
    while(p!=0){
        printf("%d ",p->data);
        p=p->next;
    }
}
//Recursive Version
void Display2(struct Node *p){
    if(p!=0){
        printf("%d ",p->data);
        Display2(p->next);
    }
}