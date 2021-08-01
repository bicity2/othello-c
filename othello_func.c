#include "othello_func.h"
#include <stdio.h>

/* print func */
int print_Othello(char play_board[8][8][8])
{
	int i=0;
	
	printf("┌───┬───┬───┬───┬───┬───┬───┬───┐\n");
	for(i=0;i<7;i++){
		printf("│ %s│ %s│ %s│ %s│ %s│ %s│ %s│ %s│\n",
				play_board[i][0], play_board[i][1], play_board[i][2], play_board[i][3],
				play_board[i][4], play_board[i][5], play_board[i][6], play_board[i][7]);
		printf("├───┼───┼───┼───┼───┼───┼───┼───┤\n");
	}
	printf("│ %s│ %s│ %s│ %s│ %s│ %s│ %s│ %s│\n",
		play_board[i][0], play_board[i][1], play_board[i][2], play_board[i][3],
		play_board[i][4], play_board[i][5], play_board[i][6], play_board[i][7]);
	printf("└───┴───┴───┴───┴───┴───┴───┴───┘\n");

	return 0;
}

/* Init func */
void Init_Othello_param(char play_board[8][8][8])
{
	int i,j;

	printf("#################\n");
	printf("# Othello Game !#\n");
	printf("#################\n");

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			sprintf(play_board[i][j], "%d", (i+1)*10+j+1);
		}
	}
	sprintf(play_board[3][3], "%s", "● ");
	sprintf(play_board[4][4], "%s", "● ");
	sprintf(play_board[4][3], "%s", "◯ ");
	sprintf(play_board[3][4], "%s", "◯ ");
}