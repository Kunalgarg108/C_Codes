#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void Count(int A[],int n,int k);
int max(int A[],int n){
     int max=INT_MIN;
     int i;
     for(i=0;i<n;i++){
        if(A[i]>max){
            max=A[i];
        }
     }
     return max;
}
int main(){
    int n,i;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of array:");
    for(i=0;i<n;i++){
       scanf("%d",&A[i]);
    }
    int k=max(A,n);
    Count(A,n,k);
    printf("Sorted array is:\n");
    for(i=0;i<n;i++){
       printf("%d ",A[i]);
    }
    return 0;
}
void Count(int A[],int n,int k){
    int i;
    int* C=(int*)calloc(k+1,sizeof(int));
    for(i=0;i<n;i++){
        C[A[i]]++;
    }
    int j=0,l=0;
    while(l<k+1){
        if(C[l]>0){
            A[j]=l;
            j++;
            C[l]--;
        }
       else{
        l++;
       }
    }
    free(C);
    C=NULL;
}
