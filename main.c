/**
  @author: Daniel S. Hono II
  @date: 2014/12/27

  todo: Need a way to read a configuration from a file
**/

#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include "symbolics.h"

int main(int argc, const char** argv) {

	int gameSize = 0; //Size of the board we want. 
	char** board = NULL; //Initial board. 
	FILE* initialConfig = NULL; //File containing the initial configuration. 

	if(argc != PARAMS) {
		fprintf(stderr, "Usage: conway [file]\n");
		exit(1);
	}

	if ( (initialConfig = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Could not open initial configuration file!\n");
		exit(1);
	}

	fscanf(initialConfig, "%d", &gameSize);
	

	board = makeBoard(gameSize);
	printBoard(board, gameSize);

	return 0;

}

//Function to create an empty game board. 
char** makeBoard(int size) {

	char** newBoard = NULL; //empty board. 
	int i = 0, j = 0, k = 0; //loop counters. 
	
	newBoard = (char**)malloc(sizeof(char*)*size);
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
	
	//Initialize everything to "O" meaning "Dead" 
	for(j = 0; j < size; j++) {
		for(k = 0; k < size; k++) {
			newBoard[j][k] = 'O';
		}
	}
		      
	return newBoard; 


}

//todo: deal with the size thing better. 
void printBoard(char** game, int size) {
	int j = 0, k = 0;
	for(j = 0; j < size; j++) {
		for(k = 0; k < size; k++) {
			printf(" %c ", game[j][k]);
		}
		printf("\n");
	}
}	
	



