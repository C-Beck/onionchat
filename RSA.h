#ifndef RSA_H_
#define RSA_H_
void keygen(long* key_n,long* key_e,long* key_d);
void RSAencrypt(char* msg,int pubkey_n,int pubkey_e,int* ecnr);
void RSAdecrypt(int* encr,int privkey_n,int privkey_d,char* msg);
#endif
