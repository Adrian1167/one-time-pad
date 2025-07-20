/* main.c */
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "otp.h"


int main(int argc, char ** argv){

    assert(argc >= 4);

    char *mode = argv[1];

    FILE *inputFile = fopen(argv[2], "r");
    if (!inputFile) {
        fprintf(stderr, "can't open input file: %s\n", argv[2]);
        perror("fopen");
        return 1;
    }

    FILE *keyFile = fopen(argv[3], strcmp(mode, "keygen") == 0 ? "w+" : "r");
    if (!keyFile) {
        fprintf(stderr, "can't open key file: %s\n", argv[3]);
        perror("fopen");
        return 1;
    }

    FILE *outputFile = NULL;
    if (strcmp(mode, "encrypt") == 0 || strcmp(mode, "decrypt") == 0) {
        outputFile = fopen(argv[4], "w");
        if (!outputFile) {
            fprintf(stderr, "Error: could not open output file '%s'\n", argv[4]);
            perror("fopen");
        }
    }

    

    if (strcmp(argv[1], "encrypt") == 0){
        encrypt(inputFile, keyFile, outputFile);
        fflush(outputFile);
    }
    else if (strcmp(argv[1], "decrypt") == 0){
        decrypt(inputFile, keyFile, outputFile);
        fflush(outputFile);
    }
    else if (strcmp(argv[1], "keygen") == 0){
        generateKey(inputFile, keyFile);
        fflush(keyFile);
        rewind(keyFile);
        rewind(inputFile);
    }
    else {
        perror("invalid mode");
    }

    fclose(inputFile);
    fclose(keyFile);
    if (outputFile) {  //handle case for when outputFile is actually NULL due to executing keygen
        fclose(outputFile);
    }

    return 0;
}