#include<stdio.h>
double taylor(int x,int n);
double taylor2(double x,int n);
int main(){
    int x,n;
    printf("Enter the number:");
    scanf("%d",&x);
    printf("Enter the terms:");
    scanf("%d",&n);
    printf("Solution is:%lf",taylor(x,n));
    return 0;
}
double taylor(int x,int n){
    static double p=1,f=1;
    double r;
    if(n==0){
        return 1;
    }
    r=taylor(x,n-1);
    p=p*x;
    f=f*n;
    return (r+(p/f));
}
double taylor2(double x,int n){
    static double S=1;
    if(n==0){
        return S;
    }
    S=1+(x/n)*S;
    return taylor2(x,n-1);
}