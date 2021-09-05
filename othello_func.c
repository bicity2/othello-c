#include "othello_func.h"
#include <stdio.h>
#include <string.h>

char play_board[8][8][8];

/* print func */
int print_Othello()
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
void Init_Othello_param()
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

/* get opsit piece */
int get_opt_piece(char player_piece[8], char opt_piece[8])
{
	if(strcmp(player_piece, "●") == 0){
		sprintf(opt_piece, "%s", "◯");
	} else if(strcmp(player_piece, "◯") == 0){
		sprintf(opt_piece, "%s", "●");
	} else {
		printf("System Error\n");
		return -1;
	}

	return 0;
}

/* set piece */
int set_piece(int index_num, char player_piece[8])
{
	sprintf(play_board[index_num/10][index_num%10], "%s ", player_piece);
	return 0;
}

/* check can I set piece */
int check_can_I_set_piece(int index_num, char player_piece[8],int updown , int rightleft)
{
	char opt_piece[8];
	int pick_index_num = index_num + rightleft + updown*10;

	if((pick_index_num+11)%10 == 0 ||  /* over left */
		(pick_index_num+11)%10 == 9 || /* over right */
		(pick_index_num+11)/10 == 0 || /* over top */
		(pick_index_num+11)/10 == 9)   /* over bottom */
	{
		return 0;
	}

	get_opt_piece(player_piece, opt_piece);


	if(strncmp(play_board[pick_index_num/10][pick_index_num%10], opt_piece, 3)!=0)
		return 0; // left is not opt piece

	while(((pick_index_num+11)%10) != 1||
			((pick_index_num+11)%10) != 8||
			((pick_index_num+11)/10) != 1||
			((pick_index_num+11)/10) != 8){
		pick_index_num = pick_index_num + rightleft + updown*10;
		if((strncmp(play_board[pick_index_num/10][pick_index_num%10], player_piece, 3) == 0) ||
		pick_index_num/10 == -1)
			break; /* find player piece over left or get most left */
		else if(strncmp(play_board[pick_index_num/10][pick_index_num%10], opt_piece, 3) != 0)
			return 0;; /* there is no player piece over left */
	}

		if(((pick_index_num+11)%10 == 0)||	/* over left */
			((pick_index_num+11)%10 ==9)||	/* over right */
			((pick_index_num+11)/10 ==0)||	/* over top */
			((pick_index_num+11)/10 ==9)){	/* over bottom */
		return 0;
	}
	while(pick_index_num != index_num){
		set_piece(pick_index_num, player_piece);
		pick_index_num = pick_index_num - rightleft - updown*10;
	}

	/* Check list bit[x]
	 * 	 up left	: 0 (0+0) *   up : 1 (0+1) *   up right	: 2 (0+2) * 
	 *      left	: 3 (3+0) *				   *	  right	: 5 (3+2) *
	 * down left	: 6 (6+0) * down : 7 (6+1) * down right : 8 (6+2) *
	 * ALL is OK    : 0x1EF */
	return 1<<((updown+1)*3 + rightleft+1);
}

/* switch player func */
int place_a_piece(int *player_flag, char player_piece[8])
{
	int inum=0;
	int ret = 0;
	int index_num = 0;
	int put_flag = 0;
	
	if(*player_flag == 0){
		sprintf(player_piece, "%s", "●");
		*player_flag = 1;
	} else if(*player_flag == 1){
		sprintf(player_piece, "%s", "◯");
		*player_flag = 0;
	} else {
		printf("System Error¥n");
		return -1;
	}

	while(1){
		print_Othello();
		ret = 1;
		printf("Order : %s\n", player_piece);
	 	printf("chose No. \n");
		scanf("%d", &inum);
		index_num = inum-11;

		if (inum<11 || (inum>18&&inum<21) || (inum>28&&inum<31) || (inum>38&&inum<41) ||
		(inum>48&&inum<51) || (inum>58&&inum<61) || (inum>68&&inum<71) || (inum>78&&inum<81) || (inum>88) ||
		strcmp(play_board[index_num/10][index_num%10], "● ")==0 ||
		strcmp(play_board[index_num/10][index_num%10], "◯ ")==0)
		{
			printf("please retry\n");
			continue;
		}
		for(int i=-1;i<2;i++){
			for(int j=-1;j<2;j++){
				if(i!=0||j!=0)
					put_flag |= check_can_I_set_piece(index_num, player_piece,i ,j);

			}
		}

		if(put_flag == 0){
			printf("put_flag error\n");
			printf("please retry\n");
			continue;
		}
		if(put_flag & 0x1EF)
			set_piece(index_num, player_piece);

		printf("put_flag = 0x%x\n", put_flag);
		return 0;
	}
}

/* game judge */
int game_judge()
{
	int count_white=0;
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(strcmp(play_board[i][j], "● ")==0)
				count_white+=1;
		}
	}

	if(count_white>18){
		printf("Win:●\n");
		printf("●:%d\n◯:%d\n", count_white, 64-count_white);
	} else if(count_white==18){
		printf("Draw\n");
	} else if(count_white<18){
		printf("Win:◯\n");
		printf("●:%d\n◯:%d\n", count_white, 64-count_white);
	} else {
		printf("System Error\n");
	}

	return 0;
}