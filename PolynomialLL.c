#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct polynode{
    int coeff;
    int exp;
    struct polynode *link;
};
struct polynode* Insertpoly(struct polynode *poly,int c,int e);
void display(struct polynode *poly);
int main()
{
    struct polynode *a=NULL;
    a=Insertpoly(a,3,14);
    a=Insertpoly(a,5,8);
    a=Insertpoly(a,6,0);
    display(a);
    return 0;
}
struct polynode* Insertpoly(struct polynode *poly,int c,int e){
    struct polynode *nn;
    nn=malloc(sizeof(struct polynode));
    nn->coeff=c;
    nn->exp=e;
    nn->link=NULL;
    if(poly==NULL){
        poly=nn;
        return poly;
    }
    struct polynode *last=poly;
    while(last->link!=NULL){
        last=last->link;
    }
    last->link=nn;
    return poly;
}
void display(struct polynode *poly){
    if(poly==NULL){
        printf("Not Present");
        return;
    }
    while(poly!=NULL){
        printf(" %dx^%d ",poly->coeff,poly->exp);
        if(poly->link!=NULL){
            printf("+");
        }
        poly=poly->link;
    }
}