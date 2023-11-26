/*
 * functions.c
 *
 *  Created on: 19. stu 2023.
 *      Author: kar1o
 */
#include <stdio.h>
#include <string.h>
#include "functions.h"

int encode(char *fileName) {

    char character, text[50000+1];
    int index;

    // read
    FILE* inputFileRead = fopen(fileName, "r");
    if (inputFileRead == NULL) {
        return -1;
    }

    index = 0;
    while((character = fgetc(inputFileRead)) != EOF) {
        text[index++] = character;
    }
    text[index] = '\0';

    if(fclose(inputFileRead) == EOF) {
    	return -1;
    }

    // encode
    index = 0;
    while(text[index] != '\0') {
        text[index++] += 2;
    };

    // write
    FILE* inputFileWrite = fopen(fileName, "w");
    if (inputFileWrite == NULL) {
    	return -1;
    }

    index = 0;
    while(text[index] != '\0') {
        fputc(text[index++], inputFileWrite);
    }

    if(fclose(inputFileWrite) == EOF) {
    	return -1;
    }

    return 0;
}

int decode(char *fileName) {

    char character, text[50000+1];
    int index;

    // read
    FILE* inputFileRead = fopen(fileName, "r");
    if (inputFileRead == NULL) {
    	return -1;
    }

    index = 0;
    while((character = fgetc(inputFileRead)) != EOF) {
        text[index++] = character;
    }
    text[index] = '\0';

    if(fclose(inputFileRead) == EOF) {
    	return -1;
    }

    // decode
    index = 0;
    while(text[index] != '\0') {
        text[index++] -= 2;
    };

    // write
    FILE* inputFileWrite = fopen(fileName, "w");
    if (inputFileWrite == NULL) {
    	return -1;
    }

    index = 0;
    while(text[index] != '\0') {
        fputc(text[index++], inputFileWrite);
    }

    if(fclose(inputFileWrite) == EOF) {
    	return -1;
    }

    return 0;
}
