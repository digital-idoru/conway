/**
  @author: Daniel S. Hono II
  @date: 2014/12/27

  todo: Need a way to read a configuration from a file
**/

#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main(int argc, const char** argv) {

	int gameSize = 0; //Size of the board we want. 
	char** board = NULL; //Initial board. 

	//todo: Make this readable from a file
	printf("Enter size of matrix: ");
	scanf("%d", &gameSize);
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

//Convention is that the file is the structured that 
//the first line contains the size of the board, an integer, 
//then the next n lines correspond to the rows of the matrix starting positions. 
void openBoard(char* filename) {



}
	



