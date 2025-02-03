#include<stdio.h>
#include<stdlib.h>
char *strndel(char a[],int start ,int length);
int main()
{
   int start,length;
   char a[100];
   puts("enter the string");
   fgets(a,100,stdin);
   printf("Enter the starting index and length:");
   scanf("%d %d",&start,&length);
   char *c=strndel(a,start,length);
   printf("%s",c);
   free(c);
   return 0;
}
char *strndel(char a[],int start, int length)
{
   
   char *b=(char *)malloc(100*sizeof(char));
    int i=0,j=0;
    while(a[i]!='\0')
    {
        if(i<start) {
            b[j]=a[i];
            i++;
            j++;
        }
      else if(i>=start+length)  {
           b[j++]=a[i++];
        }  
        else{
            i++;
        }
    }
    b[j]='\0';
   return b;
}