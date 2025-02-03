#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
   int val;
   struct Node *next;
};
struct Node* Insertatfirst(struct Node* list,int n);
int sum(struct Node *list,int x);
void print(struct Node* list);
int main()
{
    struct Node *list = NULL;
    int n,i;
    int r,x;
    printf("Enter the Total Size of linked list:");
    scanf("%d",&n);
    printf("Enter the numbers:");
    for(i=0;i<n;i++){
        scanf("%d",&r);
        list=Insertatfirst(list,r);
    }
    print(list);
    printf("\nEnter the number You want sum:");
    scanf("%d",&x);
    printf("Sum of last %d numbers of linked list is %d",x,sum(list,x));
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
int sum(struct Node *list,int x){
    struct Node *sum1=list;
    struct Node *sum2=list;
    int s1=0;
    int s2=0;
    while(1){
        x--;
        s1+=sum1->val;
        sum1=sum1->next;
        if(x==0){
            break;
        }
    }
    while(sum1!=NULL){
        s1+=sum1->val;
        s2+=sum2->val;
        sum1=sum1->next;
        sum2=sum2->next;
    }
    return (s1-s2);
}