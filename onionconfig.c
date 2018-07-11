#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password.h"

int main()
{
char *file=malloc(65);
char *name=malloc(65);
char *pass=malloc(65);
char *hash=malloc(65);
int nodes=3;
char repeat='n';
char *in=malloc(65);
printf("Are you creating a new config file or editing an existing one? (new/edit)\n");
scanf("%s",in);
if(strcmp(in,"n")==0||strcmp(in,"new")==0||strcmp(in,"N")==0||strcmp(in,"NEW")==0)
{
printf("new\n");
}
hashPass(name,pass,hash);
free(file);
free(name);
free(pass);
free(hash);
free(in);
}
