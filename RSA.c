#include "RSA.h"
#include "helper.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void keygen(int64_t* key_n,int64_t* key_e,int64_t* key_d)
{
int64_t p,q,n,e,d;
struct timeval t;

gettimeofday(&t,NULL);

srand((unsigned) t.tv_usec);

p=(int64_t)rand();
while(isPrime(p)==1)
{
	p=(int64_t)rand();
}

q=(int64_t)rand();
while(isPrime(q)==1)
{
	q=(int64_t)rand();
}

n = p * q;

printf("%lli:%lli:%lli\n",p,q,n);

int64_t ctf = lcm(p-1,q-1);

e=(int64_t)rand();
while(gcf(e,ctf)!=1)
{
	e=(int64_t)rand();
}
d=0;
while(((d*e)-1)%ctf !=0)
{
d++;
}

*key_n = n;
*key_e = e;
*key_d = d;
}

void RSAencrypt(char* msg,int pubkey_n,int pubkey_e,int* ecnr)
{

}

void RSAdecrypt(int* encr,int privkey_n,int privkey_d,char* msg)
{

}
