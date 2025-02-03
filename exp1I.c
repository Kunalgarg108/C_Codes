#include<stdio.h>
#include<limits.h>
int factorial(int);
int main()
{
   //Taking the value from user
   int n,z;
   printf("Enter the number:");
   scanf("%d",&n);
   //Sending the number to the function
   z=factorial(n);
   printf("Factorial of %d is %d",n,z);
    return 0;
}
int factorial(int n){
    if(n==1){
        return 1;
    }
    return (n*factorial(n-1));
}