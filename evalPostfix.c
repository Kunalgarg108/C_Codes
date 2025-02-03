#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct Stack{
    int top;
    int items[100];
};
bool empty(struct Stack *ps);
void push(struct Stack *ps,int x);
void pop(struct Stack *ps,int* x);
int main()
{
    int op1,op2;
    int val;
    struct Stack S;
    char a[100];
    puts("Enter the postfix Expression");
    fgets(a,100,stdin);
    S.top=-1;
    int i=0;
    char symbol;
    while(a[i+1]!='\0'){
       symbol=(a[i]);
       if(symbol!='+'&& symbol!='-'&& symbol!='*' && symbol!='/')
       {
        push(&S,(symbol-'0'));
       }
       else{
        pop(&S,&op2);
        pop(&S,&op1);
        switch(symbol){
            case '+':{
                val=op1+op2;
                break;
            }
            case '-':{
                val=op1-op2;
                break;
            }
            case '*':{
                val=op1*op2;
                break;
            }
            case '/':{
                val=op1/op2;
                break;
            }
        }
        push(&S,val);
       }
       i++;
    }
    int k;
    pop(&S,&k);
    printf("%d \n",k);
    if(empty(&S)){
    printf("Now Stack is empty");}
    return 0;
}
bool empty(struct Stack *ps){
    if(ps->top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(struct Stack *ps,int x){
    if(ps->top==98){
        printf("Overflow");
        exit(1);
    }
    (ps->items[++(ps->top)])=x;
    return;
}
void pop(struct Stack *ps,int* x){
    if(empty(ps)){
        printf("Underflow");
        exit(1);
    }
    *x=(ps->items[(ps->top)--]);
    return;
}