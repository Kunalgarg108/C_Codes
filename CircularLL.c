#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
int count(struct node *list);
struct node *Insertatptr(struct node *list,struct node *ptr,int n);
struct node *Deleteatptr(struct node *list,struct node *ptr);
void display(struct node *list);
int main()
{
    struct node *list=NULL;
    list=Insertatptr(list,list,8);
    list=Insertatptr(list,list->next,9);
    list=Insertatptr(list,list->next,7);
    list=Insertatptr(list,list,6);
    display(list);
    printf("\n%d",count(list));

}
struct node *Insertatptr(struct node *list,struct node *ptr,int n){
    struct node *nn;
    nn=malloc(sizeof(struct node));
    nn->val=n;
    if(list==NULL){
        nn->next=nn;
        list=nn;
        return list;
    }
    nn->next=ptr->next;
    ptr->next=nn;
    return list;
}
void display(struct node *list){
    if(list==NULL){
        printf("Enter list\n");
        return;
    }
    struct node *temp=list;
    do{
        printf("%d ",temp->val);
        temp=temp->next;
    }
    while(temp!=list);
    return;
}
int count(struct node *list){
    if(list==NULL){
        printf("Enter list\n");
        return 0;
    }
    int count=0;
    struct node *temp=list;
    do{
        count++;
        temp=temp->next;
    }
    while(temp!=list);
    return count;
}
struct node *Deleteatptr(struct node *list,struct node *ptr){
    if(list==NULL){
        return list;
    }
    struct node *temp=list;
    while(temp!=ptr){
        temp=temp->next;
    }
    temp->next=ptr->next;
    free(ptr);
    return list;
}