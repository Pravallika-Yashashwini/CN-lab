---BIT STUFFING---
#include<stdio.h>
#include<string.h>
void main()
{
int a[20],b[30],i,j,k,count,n;
printf("Enter frame length:");
scanf("%d",&n);
printf("Enter input frame (0's & 1's only):");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
i=0; count=1; j=0;
while(i<n)
{
if(a[i]==1)
{
b[j]=a[i];
for(k=i+1;a[k]==1 && k<n && count<5;k++)
{
j++;
b[j]=a[k];
count++;
if(count==5)
{
j++;
b[j]=0;
}
i=k;
}}
else
{
b[j]=a[i];
}
i++;
j++;
}
printf("After stuffing the frame is:");
for(i=0;i<j;i++)
printf("%d",b[i]);
}
--------------------------------------------------------------------------------------------------------------
---CHARACTER STUFFING---
#include <stdio.h>
#include<string.h>
int main()
{
    int i=0,j=0,n,pos;
    char a[20],b[20],ch;
    printf("\n---CHARACTER STUFFING/BYTE STUFFING---\n");
    printf("ENTER THE STRING:\n");
    scanf("%s",&a);
    n=strlen(a);
    printf("ENTER THE POSITION:\n");
    scanf("%d",&pos);
    if(pos>n){
        printf("INVALID POSITION!!, ENTER AGAIN:");
        scanf("%d",&pos);
    }
    printf("ENTER THE CHARACTER:\n");
    ch=getch();
    b[0]='d';
    b[1]='l';
    b[2]='e';
    b[3]='s';
    b[4]='t';
    b[5]='x';
    j=6;
    while(i<n){
        if(i==pos-1){
            b[j]='d';
            b[j+1]='l';
            b[j+3]='ch';
            b[j+4]='d';
            b[j+5]='l';
            b[j+6]='e';
            j=j+7;
        }
        if(a[i]=='d'&&a[i+1]=='l'&&a[i+2]=='e'){
            b[j]='d';
            b[j+1]='l';
            b[j+3]='e';
            j=j+3;
        }
        b[j]=a[i];
        i++;j++;
    }
    b[j]='d';
    b[j+1]='l';
    b[j+2]='e';
    b[j+3]='e';
    b[j+4]='t';
    b[j+5]='x';
    b[j+6]='\0';
    printf("\n FRAME AFTER STUFFING:\n");
    printf("%s",b);
    return 0;
}
-------------------------------------------------------------------
