#include<stdio.h>
int main(){
    typedef struct{
        int rows;
        int cols;
        int val;
    }term;
    term a[10];
    int i,j;
    int d[6][6];
    printf("Enter the values of 6X6 matrix\n");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            scanf("%d",&d[i][j]);
        }
    }
    a[0].rows=6;
    a[0].cols=6;
    int k=1;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(d[i][j]!=0){
                a[k].rows=i;
                a[k].cols=j;
                a[k].val=d[i][j];
                k++;
            }
        }
    }
    a[0].val=k-1;
    printf("Rows          Columns          Values\n");
    for(i=0;i<k;i++){
        printf("%d              %d                  %d\n",a[i].rows,a[i].cols,a[i].val);
    }
    return 0;
}