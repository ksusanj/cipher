/*
 ============================================================================
 Name        : cipher.c
 Author      : kar1o
 Version     : 1.0
 Copyright   : © 2023
 Description : Simple cipher program written in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/functions.h"

int main(void) {

	char fileName[100+1];
	int operationChoice;

    printf("Insert the absolute path to the text file (with extension) which content you want to modify:");
    scanf("%[^\n]", fileName);

	// Operations
	printf("\nChoose operation:");
	printf("\n-------------------------------------");
	printf("\n1. Encode text file %s", fileName);
	printf("\n2. Decode text file %s", fileName);
	printf("\n3. Exit");
	
	scanf("%d", &operationChoice);

	switch (operationChoice) {
		case (1):
			encode(&fileName[0]);
			break;
		case (2):
			decode(&fileName[0]);
			break;
		case (3):
			break;
		default:
			printf("\nInvalid operation!");
	}

	return EXIT_SUCCESS;
}
