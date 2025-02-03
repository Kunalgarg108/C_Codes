#include<stdio.h>
void sum();
int main()
{
    int n,i,c;
    printf("Enter the number(n) to print from 1 to n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    sum();
    return 0;
}
void sum(){
    static int sum=0;
    sum+=1;
    printf("%d ",sum);
}