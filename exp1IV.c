#include<stdio.h>
int main()
{
    int n,i;
   printf("Enter the size of the array:");
   scanf("%d",&n);
   //Taking the elements of the array
   int a[n];
   printf("Enter the elements:");
   for(i=0;i<n;i++)
   {
    scanf("%d",&a[i]);
   }
   int t=a[0];
   for(i=0;i<n;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        if(t<a[j])
        {
            t=a[j];
        }
    }
   } 
    printf("Largest element of array is %d",t);
    return 0;  
}
