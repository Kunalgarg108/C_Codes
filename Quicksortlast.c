#include<stdio.h>
void partition(int a[],int p,int r);
int Quick(int a[],int p,int r);
void swap(int* c,int* b);
int main(){
    int n,i;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    partition(a,0,n-1);
    printf("Sorted array is:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void partition(int a[],int p,int r){
    if(p<r){
        int q=Quick(a,p,r);
        partition(a,p,q-1);
        partition(a,q+1,r);
    }
}
int Quick(int a[],int p,int r)
{
    int pivot=a[r];
    int i,j;
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(a[j]<=a[r])
        {
            i=i+1;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}
void swap(int* c,int* b){
    int temp=*c;
    *c=*b;
    *b=temp;
}