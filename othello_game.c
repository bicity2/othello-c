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
	int player_flag = 0;
	char player_piece[8]; // ● or ◯
	//char play_board[8][8][8];

	Init_Othello_param();

	for (int i = 0; i<60; i++){
		ret = place_a_piece(&player_flag, player_piece);
	}
	print_Othello();

	game_judge();
	
	return 0;
}
