#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>
#include "RSA.h"
#include "helper.h"

int main()
{
	int i,n;
	int64_t r;
	struct timeval t;

	n=5;

	gettimeofday(&t,NULL);

	srand((unsigned) t.tv_usec);

	for(i=0;i<n;i++)
	{
		r=rand();
		while(isPrime(r)==1)
		{
			r=rand();
		}
		printf("%d:%d\n",r,isPrime(r));
	}

	printf("%u\n",INT64_MAX);
	printf("size of %u", sizeof(long long int));
	int64_t a = 0;
	mod_pow(&a,4,13,497);
	printf("%d\n",a);
	printf("%d\n",gcf(462,1071));
	printf("%d\n\n",lcm(21,6));
	int64_t kn,e,d;
	keygen(&kn,&e,&d);
	printf("%lli:%lli:%lli\n",kn,e,d);
	int64_t crypt,msg;
	mod_pow(&crypt,2530,e,kn);
	printf("%lli\n",crypt);
	mod_pow(&msg,crypt,d,kn);
	printf("%lli\n",msg);
	return 0;
}
