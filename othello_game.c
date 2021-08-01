/********************
 * Othello Game     *
 * Copyright Bicity *
 * 2021/07/06       *
*********************/
#include "othello_func.h"

/* main */
int main()
{
	int ret = 0;
	char play_board[8][8][8];

	Init_Othello_param(play_board);

	ret = print_Othello(play_board);
	return 0;
}