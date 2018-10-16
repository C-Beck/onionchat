#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <pwd.h>
#include "password.h"

int main()
{
	const char *homedir;
	if((homedir = getenv("HOME")) == NULL)
	{
		homedir = getpwuid(getuid())->pw_dir;
	}
	//printf("%s\n",homedir);
	FILE *file;
	char *filename=malloc(65);
	char *folder=malloc(65);
	char *name=malloc(65);
	char *pass=malloc(65);
	char *hash=malloc(65);
	int nodes=3;
	char repeat='n';
	char *in=malloc(65);
	int valid = 0;
	int mode = 0;
	while(!valid)
	{
		printf("Are you creating a new config file or editing an existing one? (new/edit)\n");
		scanf("%s",in);
		if(strcmp(in,"n")==0||strcmp(in,"new")==0||strcmp(in,"N")==0||strcmp(in,"NEW")==0)
		{
			valid=1;
			mode=1;
			//printf("new\n");
		}
		else if(strcmp(in,"e")==0||strcmp(in,"edit")==0||strcmp(in,"E")==0||strcmp(in,"EDIT")==0)
		{
			valid=1;
			mode=2;
			//printf("edit\n");
		}
		else
		{
			printf("Invalid response.\n");
		}
	}
	valid=0;
	strcpy(filename,homedir);
	strcpy(folder,homedir);
	while(!valid)
	{
		printf("Which file location?\n1) ~/.config/onionchat/config\n2) ~/.onionchat/config\n3) ~/.onionconfig\n");
		scanf("%s",in);
		char *ptr;
		switch(strtol(in,&ptr,10))
		{
			case 1:
				valid=1;
				strcat(filename,"/.config/onionchat/config");
				strcat(folder,"/.config/onionchat/");
				//printf("1\n");
				break;
			case 2:
				valid=1;
				strcat(filename,"/.onionchat/config\x00");
				strcat(folder,"/.onionchat/");
				//printf("2\n");
				break;
			case 3:
				valid=1;
				strcat(filename,"/.onionconfig");
				//strcat(folder,"/");
				//printf("3\n");
				break;
			default:
				printf("Invalid option\n");
		}
	}
	if(mode==1)
	{
		if(strcmp(folder,homedir)!=0)
		{
			mkdir(folder,0755);
		}
		if((file = fopen(filename,"w")) != NULL)
		{
			printf("File readable:%s\n",filename);
			fclose(file);
		}
		else{
			printf("File unreadable:%s\n",filename);
		}
	}
	if(mode==2)
	{
		if((file = fopen(filename,"r")) != NULL)
		{
			printf("File readable:%s\n",filename);
			fclose(file);
		}
		else{
			printf("File unreadable:%s\n",filename);
		}
	}

	hashPass(name,pass,hash);
	free(file);
	free(filename);
	free(folder);
	free(name);
	free(pass);
	free(hash);
	free(in);
}
