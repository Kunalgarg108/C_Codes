#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    int count=0;
   printf("Enter the number:");
   scanf("%d",&n);
   if(n==0 || n==1)
   {
    printf("Invalid input number is neither prime nor composite");
    exit(0);
   }
   for(i=2;i<n/2;i++)
   {
    if(n%i==0)
    {
       count++;
        break;
    }
   }
   if(count==0)
    {
        printf("Number is prime");
    }
   else
    {
       printf("number is not a prime");
    }
   
   return 0;
}