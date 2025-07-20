/* decrypt.c */

#include "otp.h"

void decrypt(FILE *inputFile, FILE *keyFile, FILE *outputFile){

    char *bufferToDecrypt;
    char *keyBuffer;
    
    size_t sizeOfBufferToDecrypt = allocateMemory(inputFile, &bufferToDecrypt);
    size_t sizeOfKey = allocateMemory(keyFile, &keyBuffer);

    int i;
    for(i = 0; i< sizeOfKey; i++){
        char c = bufferToDecrypt[i] ^ keyBuffer[i];
        fprintf(outputFile, "%c", c);
    }
    fflush(outputFile);

    free(bufferToDecrypt);
    free(keyBuffer);

}