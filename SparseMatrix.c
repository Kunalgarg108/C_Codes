#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Sparse{
    int i;
    int j;
    int v;
};
void readMatrix();
void printMatrix();
int main()
{
    struct Sparse s[11];
    readMatrix(s);
    printMatrix(s);
    return 0;
}
void readMatrix(struct Sparse s[]){
    int i;
    printf("Enter the row column dimensions less than 11:");
    scanf("%d %d",&s[0].i,&s[0].j);
    printf("Enter the non-zero entries:");
    scanf("%d",&s[0].v);
    printf("Enter the triplets:\n");
    for(i=1;i<=s[0].v;i++){
        scanf("%d %d %d",&s[i].i,&s[i].j,&s[i].v);
    }

}
void printMatrix(struct Sparse s[]){
    int i,j;
    int k=1;
    printf("Sparse Matrix:\n");
    for(i=0;i<s[0].i;i++){
        for(j=0;j<s[0].j;j++){
            if(s[k].i==i && s[k].j==j){
                printf("%3d",s[k].v);
                k++;
            }
            else{
                printf("%3d",0);
            }
        }
        printf("\n");
    }
}