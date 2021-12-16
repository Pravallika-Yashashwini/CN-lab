#include<stdio.h>
#include<conio.h>
#include<string.h>
int p10[]={3,5,2,7,4,10,1,9,8,6},
p8[]={6,3,7,4,8,5,10,9},
p4[]={2,4,3,1};
int ip[]={2,6,3,1,4,8,5,7},
ipinv[]={4,1,3,5,7,2,8,6},
ep[]={4,1,2,3,2,3,4,1};
int s0[][4]={{1,0,3,2,},{3,2,1,0},{0,2,1,3,},{3,1,3,2}};
int s1[][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
void permute(char op[],char ip[],int p[], int n)
{ 
int i;
for(i=0;i<n;i++) op[i]=ip[p[i]-1]; 
op[i]='\0';
}
void circularls(char pr[],int n)
{
int i;
char ch=pr[0]; 
for(i=0;i<n-1;i++)
pr[i]=pr[i+1];
pr[i]=ch;
}
void keygen(char k1[],char k2[],char key[])
{ char keytemp[11];
permute(keytemp,key,p10,10); 
circularls(keytemp,5);
circularls(keytemp+5,5); 
permute(k1,keytemp,p8,8);
circularls(keytemp,5);
circularls(keytemp,5);
circularls(keytemp+5,5);
circularls(keytemp+5,5);
permute(k2,keytemp,p8,8);
}
void xor(char op[],char ip[])
{
int i;
for(i=0;i<strlen(op)&&i<strlen(ip);i++) 
op[i]=(op[i]-'0')^(ip[i]-'0')+'0';
}
void sbox(char op[],char ip[],int s[][4])
{ 
int value;
value=s[(ip[0]-'0')*2+(ip[3]-'0')][(ip[1]-'0')*2+(ip[2]-'0')];
op[0]=value/2+'0';
op[1]=value%2+'0';
op[2]='\0';
}
void fk(char op[],char ip[],char k[])
{
char l[5],r[5],tmp[9],tmp1[9],tmp2[9]; 
strncpy(l,ip,4);
l[4]='\0';
strncpy(r,ip+4,4);
r[4]='\0';
permute(tmp,r,ep,8); 
xor(tmp,k);
sbox(tmp1,tmp,s0);
sbox(tmp2,tmp+4,s1);
strcat(tmp1,tmp2); 
permute(tmp,tmp1,p4,4);
xor(tmp,l);
strcat(tmp,r);
strcpy(op,tmp);
}
void sw(char pr[])
{ 
    char tmp[9];
    strncpy(tmp,pr+4,4); 
    strncpy(tmp+4,pr,4); 
    tmp[8]='\0';
    strcpy(pr,tmp);
}
void main()
{
char key[11],k1[9],k2[9],plain[9],cipher[9],tmp[9]; 
printf("enter 10 bit key:");
gets(key);
if(strlen(key)!=10)
printf("invalid key length !!");
else
{
keygen(k1,k2,key);
printf("sub key k1::"); 
puts(k1);
printf("subkey k2::");
puts(k2);
printf("enter 8 bit plain text:"); 
gets(plain);
if(strlen(plain)!=8)
printf("invalid length plain text !!");
permute(tmp,plain,ip,8);
fk(cipher,tmp,k1); 
sw(cipher); 
fk(tmp,cipher,k2); 
permute(cipher,tmp,ipinv,8); 
printf("cipher teaxt is::"); 
puts(cipher);
/* decryption process*/ 
permute(tmp,cipher,ip,8); 
fk(plain,tmp,k2);  
sw(plain);  
fk(tmp,plain,k1); 
permute(plain,tmp,ipinv,8); 
printf("decrypted text is::"); 
puts(plain);
}
getch();
}
