#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
if(argc == 1)
{
//client
}
else if(argc == 2 || argc == 3)
{
//server/node
if(strcmp(argv[1],"-s")==0)
{
//start server
printf("starting server\n");
}
else if(strcmp(argv[1],"-h")==0)
{
//check ip,start node
}
}
else
{
//too many parameters
printf("Invalid options.\nUsage:\n    %s [-s][-h ip]\n",argv[0]);
}
}
