#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
void pop(struct node **list);
void push(struct node **list,int n);
void Display(struct node *list);
int main()
{
   struct node *list=NULL;
   push(&list,3);
   push(&list,4);
   push(&list,5);
   push(&list,6);
   push(&list,7);
   Display(list);
   pop(&list);
   pop(&list);
   Display(list);
}
void pop(struct node **list){
    if(*list==NULL){
        printf("\nUnderflow\n");
        return;
    }
    struct node *temp;
    temp=*list;
    *list=(*list)->next;
    free(temp);
    return;
}
void push(struct node**list,int n){
    struct node *nn;
    nn=malloc(sizeof(struct node));
    nn->val=n;
    nn->next=*list;
    *list=nn;
    return;
}
void Display(struct node *list){
    while(list!=NULL){
        printf("%3d",list->val);
        list=list->next;
    }
    printf("\n");
    return;
}