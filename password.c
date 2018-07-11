#include <openssl/sha.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "password.h"
void shaToHex(unsigned char* hash, char* hashstr)
{
for(int i=0;i<64;i++)
{
sprintf(&hashstr[i*2],"%02x",hash[i]);
}
hashstr[128]=0;
}
void hashPass(char* name, char* pass, char* hash)
{
char *data1=malloc(strlen(name)+strlen(pass)+2);
char *data2=malloc(strlen(name)+130);
strcpy(data1,name);
strcat(data1,".");
strcat(data1,pass);
char *hash1=malloc(SHA512_DIGEST_LENGTH);
SHA512(data1,strlen(data1),hash1);
char *hashstr1=malloc(129);
shaToHex(hash1,hashstr1);
strcpy(data2,hashstr1);
strcat(data2,".");
strcat(data2,name);
char *hash2=malloc(SHA512_DIGEST_LENGTH);
SHA512(data2,strlen(data2),hash2);
char *hashstr2=malloc(129);
shaToHex(hash2,hashstr2);
strncpy(hash,hashstr2+32,64);
free(data1);
free(data2);
free(hash1);
free(hash2);
free(hashstr1);
free(hashstr2);
return;
}
