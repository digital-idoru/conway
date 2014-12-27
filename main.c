/**
  @author: Daniel S. Hono II
  @date: 2014/12/27

  todo: Need a way to read a configuration from a file
**/

#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main(int argc, const char** argc) {

	int gameSize = 0; //Size of the board we want. 
	
	//todo: Make this readable from a file
	prinf("Enter size of matrix: ");
	scanf("%d", &gameSize);


	return 0;

}

//Function to create an empty game board. 
char** makeBoard(int size) {

	char** newBoard = NULL;
	int i = 0; 
	
	newBoard = (char**)malloc(sizeof(char)*size);
	if(newBoard == NULL) {
		fprintf(stderr, "Could not allocate heap space for new game board!\n");
		exit(1);
	}

	for(i = 0; i < size; i++) {
		newBoard[i] = (char*)malloc(sizeof(char)*size);
		if(newBoard[i] == NULL) {
			fprintf(stderr, "Error: Could not allocate heap space for rows!\n");
		}
	}
		      
	return newBoard; 


}
