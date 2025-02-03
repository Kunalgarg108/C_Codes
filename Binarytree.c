#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int val;
    struct node *right;
};
struct node *maketree(int x);
void display_preorder(struct node *tree);
void display_inorder(struct node *tree);
void display_postorder(struct node *tree);
int main()
{
    struct node *root;
    root=maketree(7);
    root->left=maketree(3);
    root->right=maketree(5);
    root->left->left=maketree(1);
    root->left->right=maketree(9);
    printf("Pre Order tree :\n");
    display_preorder(root);
    printf("\nIn Order tree :\n");
    display_inorder(root);
    printf("\nPost Order tree :\n");
    display_postorder(root);
}
struct node *maketree(int x){
    struct node *p;
    p=malloc(sizeof(struct node));
    p->val=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void display_preorder(struct node *tree){
    if(tree!=NULL){
        printf("%d ",tree->val);
        display_preorder(tree->left);
        display_preorder(tree->right);
    }
    return;
}
void display_inorder(struct node *tree){
    if(tree!=NULL){
        display_preorder(tree->left);
        printf("%d ",tree->val);
        display_preorder(tree->right);
    }
    return;
}
void display_postorder(struct node *tree){
    if(tree!=NULL){
        display_preorder(tree->left);
        display_preorder(tree->right);
        printf("%d ",tree->val);
    }
    return;
}