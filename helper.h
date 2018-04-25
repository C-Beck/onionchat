#include <stdint.h>

#ifndef HELPER_H_
#define HELPER_H_
int64_t gcf(int64_t a,int64_t b);
int64_t lcm(int64_t a,int64_t b);
void mod_pow(int64_t* ans,int64_t base,int64_t exp,int64_t mod);
int isPrime(int num);
#endif
