#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
   int val;
   struct Node *next;
};
struct Node* Insertatfirst(struct Node* list,int n);
struct Node* Insertatlast(struct Node* list,int n);
struct Node* Deletefirst(struct Node* list);
struct Node* DeleteLast(struct Node* list);
struct Node* DeleteAny(struct Node* list,int n);
struct Node* DeleteAll(struct Node* list);
void print(struct Node* list);
int main()
{
    struct Node *list = NULL;
    int n,i;
    int r;
    printf("Enter the Total Size of linked list(Even Number):");
    scanf("%d",&n);
    printf("Enter the numbers to insert at first:");
    for(i=0;i<n/2;i++){
        scanf("%d",&r);
        list=Insertatfirst(list,r);
    }
    printf("Enter the numbers to insert at last");
    for(i=0;i<n/2;i++){
        scanf("%d",&r);
        list=Insertatlast(list,r);
    }
    printf("Linked list after insertion:\n");
    print(list);
    list=Deletefirst(list);
    list=DeleteLast(list);
    printf("\nEnter the number to be deleted from list:");
    scanf("%d",&r);
    list=DeleteAny(list,r);
    printf("After deletion of first,last and given number:\n");
    print(list);
    list=DeleteAll(list);
    free(list);
    return 0;
}
struct Node* Insertatfirst(struct Node *list,int n){
    struct Node *nn;
    nn=malloc(sizeof(struct Node));
    if(nn==NULL){
        printf("Error");
        exit(1);
    }
    nn->val=n;
    nn->next=list;
    list=nn;
    return list;
}
void print(struct Node *list){
    while(list!=NULL){
        printf("%3d",list->val);
        list=list->next;
    }
    return;
}
struct Node* Insertatlast(struct Node *list,int n){
    struct Node* nn;
    nn=(struct Node*)malloc(sizeof(struct Node));
    nn->val=n;
    nn->next=NULL;
    struct Node* temp;
    temp=list;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nn;
    return list;
}
struct Node *DeleteAny(struct Node* list,int n){
    struct Node *cur,*prev;
    prev=NULL;
    cur=list;
    while(cur!=NULL && cur->val!=n){
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL){
        printf("not present");
        return list;
    }
    if(prev==NULL){
        list=list->next;
    }
    else{
        prev->next=cur->next;
        free(cur);
    }
    return list;
}
struct Node* Deletefirst(struct Node*list){
    struct Node* temp;
    if(list==NULL){
        return list;
    }
    else{
    temp=list;
    list=list->next;
    free(temp);
    return list;
    }
}
struct Node* DeleteLast(struct Node* list){
    struct Node *cur = list;
    struct Node *prev = NULL;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    return list;
}
struct Node* DeleteAll(struct Node* list){
    struct Node *prev = list;
    if(prev->next==NULL){
        free(prev);
    }
    while(prev!=NULL){
    struct Node *todelete = list;
    prev = prev->next;
    free(todelete); 
    }
    return list;
}