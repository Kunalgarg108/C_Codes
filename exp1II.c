#include<stdio.h>
int main(){
    //For positive numbers only
    int n,r;
    int t;
    int sum=0;
   printf("Enter the number:");
   scanf("%d",&n);
   t=n;
   while(n!=0){
    r=n%10;
    sum=sum*10+r;
    n=n/10;
   }
   if(t==sum){
    printf("Number is a palindrome");
   }
   else
   {
    printf("Number is not a palindrome");
   }
   return 0;
}