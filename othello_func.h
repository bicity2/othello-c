/********************
 * Othello Game     *
 * Copyright Bicity *
 * 2021/07/06       *
*********************/

#ifndef INCLUDE_OTHELLO_FUNC
#define INCLUDE_OTHELLO_FUNC

/* prototype declaration */
int print_Othello();
void Init_Othello_param();
int place_a_piece();
int set_piece();
int get_opt_piece();
int check_can_I_set_piece();
int game_judge();

/* global variable */
extern char play_board[8][8][8];

#endif
