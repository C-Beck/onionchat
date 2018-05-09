#ifndef xorCypher_H_
#define xorCypher_H_
void shaToHex(unsigned char * hash, char* hashstr);
void encrypt(char* hashstr, char* input, char* output);
void decrypt(char* hashstr, char* input, char* output);
void keygen(char* ip, char* pass, char* key);
#endif
