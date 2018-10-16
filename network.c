#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include "network.h"
void get_ip(char *ip)
{
	FILE *in=NULL;

	in = popen("ip route get '8.8.8.8' | head -1 | cut -d' ' -f7","r");
	fgets(ip,16,in);
	pclose(in);
	return;
}

int check_ip(char *ip)
{
	regex_t regex;
	int reti;
	char msgbuf[100];
	reti = regcomp(&regex,"\\b((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b",REG_EXTENDED);
	if(reti)
	{
		fprintf(stderr,"Could not compile regex\n");
		exit(1);
	}

	reti = regexec(&regex,ip,0,NULL,0);
	if(!reti)
	{
		return 0;
	}
	else if(reti == REG_NOMATCH)
	{
		return 1;
	}
	else
	{
		regerror(reti,&regex,msgbuf,sizeof(msgbuf));
		fprintf(stderr,"Regex match failed: %s\n",msgbuf);
		exit(1);
	}
}
