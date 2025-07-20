/* otp.h */

#ifndef OTP_H
#define OTP_H

#include <stdio.h>
#include <stdlib.h>

size_t calculateSizeOfFile(FILE *file);
size_t allocateMemory(FILE *file, char **buffer);
void generateKey(FILE *in, FILE *out);
void encrypt(FILE *in, FILE *key, FILE *out);
void decrypt(FILE *in, FILE *key, FILE *out);

#endif