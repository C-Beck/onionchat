#include <stdio.h>
#include "network.h"
void get_ip(char *ip)
{
FILE *in=NULL;

in = popen("ip route get '8.8.8.8' | head -1 | cut -d' ' -f7","r");
fgets(ip,16,in);
pclose(in);
return;
}
