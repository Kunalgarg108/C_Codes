#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct Queue{
    int f;
    int r;
    int size;
    struct TreeNode **arr;
};
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void enqueue(struct Queue *q,struct TreeNode* root);
struct TreeNode *dequeue(struct Queue *q);
bool isEmpty(struct Queue *q);
struct TreeNode *Create(int x);
void Level_order_traversal(struct TreeNode* root);
int main()
{
    struct TreeNode *root=NULL;
    root=Create(30);
    root->left=Create(40);
    root->left->left=Create(50);
    root->right=Create(60);
    root->right->left=Create(70);
    root->left->right=Create(80);
    root->right->right=Create(90);
    Level_order_traversal(root);
}

void enqueue(struct Queue *q,struct TreeNode* root){
    if(q->f==q->size-1){
        printf("Queue is full");
        return;
    }
    (q->f)++;
    q->arr[q->f]=root;
    return;
}

struct TreeNode *dequeue(struct Queue *q){
    if(q->f==q->r){
        printf("Queue is empty");
        return NULL;
    }
    (q->r)++;
    return q->arr[q->r];
}

bool isEmpty(struct Queue *q){
    if(q->f==q->r){
        return true;
    }
    return false;
}

struct TreeNode *Create(int x){
    struct TreeNode *nn;
    nn=malloc(sizeof(struct TreeNode));
    nn->val=x;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

void Level_order_traversal(struct TreeNode* root){
    struct Queue que;
    que.size=20;
    que.f=que.r=-1;
    que.arr=(struct TreeNode **)malloc(que.size*sizeof(struct TreeNode *));
    printf("%d  ",root->val);
    enqueue(&que,root);
    while(!isEmpty(&que)){
        root=dequeue(&que);
        if(root->left){
            printf("%d  ",root->left->val);
            enqueue(&que,root->left);
        }
        if(root->right){
            printf("%d  ",root->right->val);
            enqueue(&que,root->right);
        }
    }
}