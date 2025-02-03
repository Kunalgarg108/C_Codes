#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int val;
    int height;
    struct Node *left;
    struct Node *right;
};

int Height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    int left=Height(root->left);
    int right=Height(root->right);
    return left>right?left+1:right+1;
}

int B_F(struct Node *root){
    if(root==NULL){
        return 0;
    }
    int left=root && root->left?root->left->height:0;
    int right=root && root->right?root->right->height:0;
    return left-right;
}

struct Node *LLRotation(struct Node *root){
    struct Node *rootl=root->left;
    struct Node *rootlr=rootl->right;
    rootl->right=root;
    root->left=rootlr;
    root->height=Height(root);
    rootl->height=Height(rootl);
    return rootl;
}

struct Node *LRRotation(struct Node *root){
    struct Node *rootl=root->left;
    struct Node *rootlr=rootl->right;
    rootl->right=rootlr->left;
    root->left=rootlr->right;
    rootlr->left=rootl;
    rootlr->right=root;
    root->height=Height(root);
    rootl->height=Height(rootl);
    rootlr->height=Height(rootlr); 
    return rootlr;
}

struct Node *RLRotation(struct Node *root){
    struct Node *rootr=root->right;
    struct Node *rootrl=rootr->left;
    rootr->left=rootrl->right;
    root->right=rootrl->left;
    rootrl->left=root;
    rootrl->right=rootr;
    root->height=Height(root);
    rootr->height=Height(rootr);
    rootrl->height=Height(rootrl);
    return rootrl;
}

struct Node *RRRotation(struct Node *root){
    struct Node *rootr=root->right;
    struct Node *rootrl=rootr->left;
    rootr->left=root;
    root->right=rootrl;

    root->height=Height(root);
    rootr->height=Height(rootr);
    return rootr;
}

struct Node *Insert_BST(struct Node *root,int x){
    if(root==NULL)
    {
        struct Node *nn=NULL;
        nn=malloc(sizeof(struct Node));
        nn->val=x;
        nn->height=1;
        nn->left=NULL;
        nn->right=NULL;
        return nn;
    }
    if(x<root->val){
        root->left=Insert_BST(root->left,x);
    }
    else if(x>root->val){
        root->right=Insert_BST(root->right,x);
    }
    root->height=Height(root);
    if(B_F(root)==2 && B_F(root->left)==1){
        return LLRotation(root);
    }
    else if(B_F(root)==2 && B_F(root->left)==-1){
        return LRRotation(root);
    }
    else if(B_F(root)==-2 && B_F(root->right)==1){
        return RLRotation(root);
    }
    else if(B_F(root)==-2 && B_F(root->right)==-1){
        return RRRotation(root);
    }

    return root;
}

void display_preorder(struct Node *tree){
    if(tree!=NULL){
        printf("%d ",tree->val);
        display_preorder(tree->left);
        display_preorder(tree->right);
    }
    return;
}

int main()
{
    struct Node *root=NULL;
    root=Insert_BST(root,50);
    root=Insert_BST(root,40);
    root=Insert_BST(root,30);
    root=Insert_BST(root,20);
    root=Insert_BST(root,10);
    root=Insert_BST(root,60);
    root=Insert_BST(root,70);
    display_preorder(root);
}