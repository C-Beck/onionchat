#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
#include <stdlib.h>

void shaToHex(unsigned char * hash, char* hashstr)
{
for(int i = 0; i<64; i++)
{
sprintf(&hashstr[i*2],"%02x",hash[i]);
}
hashstr[128]=0;
}

void encrypt(char* hashstr, char* input, char* output)
{
int key;
char *p;
char sub[3];
for(int i = 0; i < strlen(input); i++)
{
strncpy(sub,hashstr + (i *2),2);
sub[2]=0;
key = strtol(sub, &p, 16);

sprintf(&output[i*2],"%02x",((int)input[i] ^ key));
}
output[strlen(input)*2]=0;
}

void decrypt(char* hashstr, char* input, char* output)
{
int key;
int let;
char *p1;
char *p2;
char sub1[3];
char sub2[3];
for(int i = 0; i < strlen(input)/2;i++)
{
strncpy(sub1,hashstr + (i*2),2);
sub1[2]=0;
key = strtol(sub1,&p1,16);
strncpy(sub2,input + (i*2),2);
sub2[2]=0;
let = strtol(sub2,&p2,16);
//printf("%s:%d:%s:%d",sub1,key,sub2,let);
output[i]=(char)(let ^ key);
}
output[strlen(input)/2]=0;
}

int main()
{
char data[]="";
char hash[SHA512_DIGEST_LENGTH];
SHA512(data,strlen(data),hash);
char foo[129];
shaToHex(hash,foo);
printf("%s\n",foo);

char *bar1, *bar2;
char* input="this is a test.";
printf("%s\n",input);
encrypt(foo,input,bar1);
printf("%s\n",bar1);
decrypt(foo,bar1,bar2);
printf("%s\n",bar2);
return 0;
}
