#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
   int val;
   struct Node *next;
};
struct Node* Insertatlast(struct Node* list,int n);
struct Node *Zigzaglist(struct Node *list1,struct Node *list2);
void display(struct Node* list);
int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    int n,i;
    int r;
    printf("Enter the Total Size of linked list1:");
    scanf("%d",&n);
    printf("Enter the numbers of first list:");
    for(i=0;i<n;i++){
        scanf("%d",&r);
        list1=Insertatlast(list1,r);
    }
    printf("Enter the Total Size of linked list2:");
    scanf("%d",&n);
    printf("Enter the numbers of second list:");
    for(i=0;i<n;i++){
        scanf("%d",&r);
        list2=Insertatlast(list2,r);
    }
    display(list1);
    display(list2);
    struct Node *result=Zigzaglist(list1,list2);
    display(result);
}
void display(struct Node *list){
    while(list!=NULL){
        printf("%3d",list->val);
        list=list->next;
    }
    printf("\n");
    return;
}
struct Node* Insertatlast(struct Node *list,int n){
    struct Node* nn;
    nn=(struct Node*)malloc(sizeof(struct Node));
    nn->val=n;
    nn->next=NULL;
    if(list==NULL){
        return nn;
    }
    struct Node* temp;
    temp=list;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nn;
    return list;
}
struct Node *Zigzaglist(struct Node *list1,struct Node *list2){
    struct Node *temp1=list1;
    struct Node *temp2=list2;
    struct Node *temp3=list1;
    while(temp1!=NULL && list2!=NULL)
    { 
        temp3=temp1->next;
        temp1->next=list2;
        list2=list2->next;
        if(temp3 != NULL) {
            temp2->next=temp3;
        }
        temp1=temp3;
        temp2=list2;
    }
    if(list2!=NULL  && temp1!=NULL){
       temp1->next=list2;
    }
    return list1;
}