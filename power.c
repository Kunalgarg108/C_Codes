#include<stdio.h>
int power(int x,int n);

int main(){
    int x,n;
    printf("Enter the number:");
    scanf("%d",&x);
    printf("Enter the power:");
    scanf("%d",&n);
    int k=power(x,n);
    printf("Solution is:%d",k);
    return 0;
}

int power(int x,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return (power(x*x,n/2));
    }
    else{
        return (x*power(x*x,(n-1)/2));
    }
}