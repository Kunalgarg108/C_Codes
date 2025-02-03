#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct Stack{
    int top;
    int items[7];
};
void pop();
void push();
bool empty();
int main()
{
   int n;
   struct Stack S;
   printf("Enter the size of array:");
   scanf("%d",&n);
   int i,x;
   int und=0;
   int ovr=0;
   int y=0;
   S.top=-1;
   printf("Enter the elements:");
   for(i=0;i<n;i++){
      scanf("%d",&x);
      push(&S,&x,&ovr);
      if(ovr){
        break;
      }
    }
   printf("Output of Stack:\n");
   for(i=0;i<n;i++){
      pop(&S,&y,&und);
      if(und){
        printf("Underflow\n");
        break;
      }
      else{
        printf("%d\n",y);
      }
   }
}
bool empty(struct Stack *ps){
    if(ps->top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(struct Stack *ps,int *x,int *pour){
    if(ps->top==5){
        printf("Overflow\n");
        *pour=1;
        return;
    }
    (ps->items[++(ps->top)])=*x;
    return;
}
void pop(struct Stack *ps,int *px,int *pund){
    if(empty(ps)){
        *pund=1;
        return;
    }
    *pund=0;
    *px=ps->items[ps->top--];
    return;
}
