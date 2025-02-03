#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Element{
    int row;
    int col;
    int value;
};
struct Sparse{
    int m;
    int n;
    int x;
    struct Element *ele;
};
void readMatrix(struct Sparse *s);
void printMatrix(struct Sparse s);
int main()
{ 
   struct Sparse s;
   readMatrix(&s);
   printMatrix(s);
   return 0;
}
void readMatrix(struct Sparse *s){
    int i;
    printf("Enter the dimensions separating spaces:");
    scanf("%d %d",&s->m,&s->n);
    printf("Enter the number of non-zero entries:");
    scanf("%d",&s->x);
    s->ele=(struct Element *)malloc(s->x*sizeof(struct Element));
    printf("Enter the entries:\n");
    for(i=0;i<s->x;i++){
    scanf("%d %d %d",&s->ele[i].row,&s->ele[i].col,&s->ele[i].value);
    }
}
void printMatrix(struct Sparse s){
    int i,j;
    int k=0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==(s.ele[k].row) && j==(s.ele[k].col))
            {printf("%3d",s.ele[k++].value);}
            else
            {
                printf("%3d",0);
            }
        }
        printf("\n");
    }
}