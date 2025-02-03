#include<stdio.h>
int main()
{
     int n,i,j,k,l;
   printf("Enter the size of pyramid:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
    for(j=i;j<n;j++)
    {
        printf(" ");
    }
    for(k=0;k<i;k++)
    {  
         printf("%c",65+k);
    }
    for(l=1;l<i;l++)
    {
        printf("%c",65-l+i-1);
    }
    printf("\n");
   }
   return 0;
}