#include<stdio.h>
int main()
{
    int n,i,key,j;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    printf("sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
return 0;
}