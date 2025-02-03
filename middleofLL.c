//Floyd's Cycle Finding Algorithm(Hare and Tortoise Algorithm)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct node* Insertatlast(struct node *list,int n);
int middle(struct node *list);
void display(struct node *list);

int main()
{
    struct node *list=NULL;
    list=Insertatlast(list,1);
    list=Insertatlast(list,2);
    list=Insertatlast(list,3);
    list=Insertatlast(list,4);
    list=Insertatlast(list,5);
    list=Insertatlast(list,6);
    list=Insertatlast(list,7);
    list=Insertatlast(list,8);
    list=Insertatlast(list,9);
    list=Insertatlast(list,10);
    list=Insertatlast(list,11);
    list=Insertatlast(list,12);
    list=Insertatlast(list,13);
    list=Insertatlast(list,14);
    display(list);
    int x;
    x=middle(list);
    printf("\n%d ",x);
    return 0;
}

struct node* Insertatlast(struct node *list,int n){
    struct node* nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->val=n;
    nn->next=NULL;
    if(list==NULL){
        return nn;
    }
    struct node* temp;
    temp=list;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nn;
    return list;
}

void display(struct node *list){
    while(list!=NULL){
        printf("%3d",list->val);
        list=list->next;
    }
    return;
}

int middle(struct node *list){
    struct node *slow=list;
    struct node *fast=list;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return (slow->val);
}