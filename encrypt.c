/* encrypt.c */

#include "otp.h"

void encrypt(FILE *inputFile, FILE *keyFile, FILE *outputFile){

    char *bufferToEncrypt;
    char *keyBuffer;
    
    size_t sizeOfBufferToEncrypt = allocateMemory(inputFile, &bufferToEncrypt);
    size_t sizeOfKey = allocateMemory(keyFile, &keyBuffer);

    int i;
    for(i = 0; i < sizeOfKey; i++){
        char c = bufferToEncrypt[i] ^ keyBuffer[i];
        fprintf(outputFile, "%c", c);
    }
    fflush(outputFile);

    free(bufferToEncrypt);
    free(keyBuffer);
}