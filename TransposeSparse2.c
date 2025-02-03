#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Sparse{
    int row;
    int col;
    int value;
};
void transpose();
int main()
{
    int i;
    int size1,size2,size3;
    printf("Enter the dimensions:");
    scanf("%d %d",&size1,&size2);
    printf("Enter the number of non-zero entries:");
    scanf("%d",&size3);
    struct Sparse a[size3+1];
    struct Sparse b[size3+1];
    a[0].row=size1;
    a[0].col=size2;
    a[0].value=size3;
    printf("Enter the triples:\n");
    for(i=1;i<size3+1;i++){
      scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].value);
    }
    transpose(a,b);
    printf("Transpose:\n");
    for(i=0;i<size3+1;i++){
        printf("%d %d %d\n",b[i].row,b[i].col,b[i].value);
    }
    return 0;
}
void transpose(struct Sparse a[],struct Sparse b[]){
     int c=b[0].row=a[0].col;
    int r=b[0].col=a[0].row;
    int n=b[0].value=a[0].value;
    int i,j;
    int *rowcol=(int *)calloc(c,sizeof(int));
    int *startposition=(int *)malloc(c*sizeof(int));
    for(i=1;i<=n;i++){
        rowcol[a[i].col]++;
    }
    startposition[0]=1;
    for(i=1;i<c;i++){
        startposition[i]=startposition[i-1]+rowcol[i-1];
    }
    for(i=1;i<=n;i++){
       j=startposition[a[i].col]++;
       b[j].row=a[i].col;
       b[j].col=a[i].row;
       b[j].value=a[i].value;
    }
    free(rowcol);
    free(startposition);
}