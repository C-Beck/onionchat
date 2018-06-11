#include <string.h>
#include <stdio.h>
#include "network.h"

int main(int argc, char *argv[])
{
if(argc == 1)
{
//client
printf("starting client\n");
}
else if(argc == 2 && strcmp(argv[1],"-s")==0)
{
//start server
printf("starting server\n");
}
else if(argc ==3 && strcmp(argv[1],"-h")==0)
{
//check ip,start node
if(!check_ip(argv[2]))
{
printf("Starting node.\nConnecting to %s\n",argv[2]);
}
else
{
//bad IP
printf("Invalid ip\n");
return 1;
}
}
else
{
//too many parameters
printf("Invalid options.\nUsage:\n    %s [-s|-h ip]\n",argv[0]);
return 1;
}
}
