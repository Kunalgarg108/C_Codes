#include<stdio.h>
#include<stdlib.h>
char *strdel(char a[],char b);
int main()
{
    char a[100];
    char b;
    //Getting the string from the user
    printf("Enter the string:");
    fgets(a,100,stdin);
    printf("Enter the character to be removed:");
    scanf("%c",&b);
    //sending the string to the function
    char* c=strdel(a,b);
    printf("%s",c);
    free(c);
}
char *strdel(char a[],char b){
    char* c=(char*)malloc(100*sizeof(char));
    int i,t,j;
    //coping the characters to another string before b
    for(i=0;i<100;i++)
    {
        if(a[i]==b)
       { break;}
       else{
        c[i]=a[i];
        t=i;
       }
    }
    //coping the characters to another string after b
    for(j=t+1;j<100;j++){
        c[j]=a[j+1];
    }
    c[j]='\0';
    return c;
}