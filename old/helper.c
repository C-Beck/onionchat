#include "helper.h"
#include <stdint.h>

int64_t gcf(int64_t a,int64_t b)
{
int64_t t;
while(b != 0)
{
	t = b;
	b = a % b;
	a = t;
}
return a;
}

int64_t lcm(int64_t a,int64_t b)
{
return (a / gcf(a,b)) * b;
}

void mod_pow(int64_t* ans,int64_t base,int64_t exp,int64_t mod)
{
if(mod==1)
{
	*ans = 0;
	return;
}
int64_t c = 1;
for(int e_prime = 1; e_prime <= exp; e_prime++)
{
	c = (c * base) % mod;
}
*ans = c;
return;
}

int isPrime(int num)
{
if(num <= 1)
{
	return 1;
}
else if(num <= 3)
{
	return 0;
}
else if(num%2==0||num%3==0)
{
	return 1;
}
int i = 5;
while(i * i <= num)
{
	if(num%i==0||num%(i+2)==0)
	{
		return 1;
	}
		i=i+6;
}
return 0;
}
