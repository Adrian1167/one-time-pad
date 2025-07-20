/* utils.c */

#include "otp.h"

size_t calculateSizeOfFile(FILE *file){

    fseek(file, 0, SEEK_END); // move pointer to the end of the file
    size_t size = ftell(file); //get current pointer position (file size)
    rewind(file); //move pointer back to the beginning

    return size;
}

size_t allocateMemory(FILE * file, char **buffer){

    size_t size = calculateSizeOfFile(file);

    *buffer = malloc(size + 1);
    if (!buffer) {
        perror("memory allocation failed");
        return 1;
    }

    size_t bytesRead = fread(*buffer, 1, size, file);
    (*buffer)[bytesRead] = '\0';

    return bytesRead;

}