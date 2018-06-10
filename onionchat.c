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
}
else
{
printf("Invalid options.\nUsage:\n    %s [-s][-h ip]\n",argv[0]);
}
}
