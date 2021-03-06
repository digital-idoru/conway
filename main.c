/**
  @author: Daniel S. Hono II
  @date: 2014/12/27

  todo: Need a way to read a configuration from a file
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	if ( (initialConfig = fopen(argv[FILEPARAM], "r")) == NULL) {
		fprintf(stderr, "Could not open initial configuration file!\n");
		exit(1);
	}
	
	
	board = extractBoard(initialConfig);
	if(board == NULL) {
		fprintf(stderr, "Something has gone horribly wrong...\n");
		exit(1);
	}

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

//Function for creating a game board from a file. 
//todo: clean up the reading the size part.
char** extractBoard(FILE* gameBoard) {

	char** extracted = NULL; //Game board extracted from the file
	int gameSize = 0; //Size of the board, i.e. the NxN matrix. 
	int i = 0, j = 0; //Loop counters row i,column j
	char size[2]; //clean this up eventually. 
 
	fgets(size, 2, gameBoard); //eww 
	gameSize = atoi(size);
	extracted = makeBoard(gameSize); //Create a blank board to start with. 
	printBoard(extracted, gameSize); 
	for(i = 0; i < gameSize; i++) {
		for(j = 0; j < gameSize; j++) {
			fscanf(gameBoard, " %c", &extracted[i][j]); //the trick here is to use the space in front of the %c. 
		}
	}
	printBoard(extracted, gameSize);
	return extracted; 


}


