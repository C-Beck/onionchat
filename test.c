#include "xorCypher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char* key = malloc(129);
char* msg = "testing 123";
char* encr = malloc(strlen(msg)*2+1);
char* decr = malloc(strlen(encr)/2+1);
char* ip = "127.0.0.1";
char* pass = "test";

printf("%s\n",msg);
keygen(ip,pass,key);
printf("%s\n",key);
encrypt(key,msg,encr);
printf("%s\n",encr);
decrypt(key,encr,decr);
printf("%s\n",decr);

free(key);
free(encr);
free(decr);
return 0;
}
