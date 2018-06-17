#ifndef password_H_
#define password_H_
void shaToHex(unsigned char* hash, char* hashstr);
void hashPass(char* name, char* pass, char* hash);
#endif
