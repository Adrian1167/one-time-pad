/* keygen.c */

#include "otp.h"

void generateKey(FILE *fileToEncrypt, FILE *keyFile){

    size_t size = calculateSizeOfFile(fileToEncrypt);
    for(;size;size--){
        char c = rand() % 256;
        fprintf(keyFile, "%c", c);
    }
}