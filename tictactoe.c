#include <stdio.h>
#include <stdbool.h>
#include "tictactoe.h"

int main()
{
	char grid[ROWS][COLUMNS] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int which_player = 0;
	int player1_move = 0;
	int player2_move = 0;
	int row = 0, col = 0;
	int loop_counter = 0;
	int winner = 0;
	bool game_still_running = true;

	while(game_still_running)
	{	
		loop_counter++;
		printf("-------------Player One's turn to play--------------\n");
		printf("Which position do you wish to play? (1-9)\n");
		scanf("%d", &player1_move);
		
		while((player1_move < 1)  || (player1_move > 9))
		{
			printf("Please enter a value between 1-9\n");
			scanf("%d", &player1_move);
		}

		getCoordinates(player1_move, &row, &col);
		grid[row][col] = 'X';
		printGame(grid);

		/* Check if player1 won */
		if(loop_counter >= 3)
		{
			/* Check if player2 won */
			winner = findWinner(grid);
			if(winner == 1)
			{
				printf("Player One is the winner!!\n");
				game_still_running = false;
				break;
			}
		}
	
		printf("-------------Player Two's turn to play--------------\n");
		printf("Which position do you wish to play? (1-9)\n");
		scanf("%d", &player2_move);

		while((player2_move < 1)  || (player2_move > 9))
		{
			printf("Please enter a value between 1-9\n");
			scanf("%d", &player2_move);
		}

		getCoordinates(player2_move, &row, &col);
		grid[row][col] = 'O';
		printGame(grid);
		printf("loopctr : %d \n", loop_counter);
		if(loop_counter >= 3)
		{
			/* Check if player2 won */
			winner = findWinner(grid);
			if(winner == 2)
			{
				printf("Player Two is the winner!!\n");
				game_still_running = false;
				break;
			}
		}

	}

	return 0;
}

void printGame(char grid[ROWS][COLUMNS])
{
	printf("----------------------\n");
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLUMNS; j++)
		{
			printf("    %c ", grid[i][j]);
		}
		printf("\n");
	}
	printf("----------------------\n");

}


void getCoordinates(int position, int *row, int *col)
{
	position--;
	*row = position / 3;
	*col = position % 3;
}

int findWinner(char grid[ROWS][COLUMNS])
{
	int cnt_ver_p1 = 0, cnt_hor_p1 = 0, cnt_diag_p1 = 0;
	int cnt_ver_p2 = 0, cnt_hor_p2 = 0, cnt_diag_p2 = 0;

    for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLUMNS; j++)
		{
			/* Look for 3 X's vertically*/
			if(grid[i][j] == 'X')
			{
				cnt_ver_p1++;
			}
			/* Look for 3 X's horizontally*/
			else if(grid[j][i] == 'X')
			{
				cnt_hor_p1++;
			}
			/* Look for 3 O's vertically*/
			else if(grid[i][j] == 'O')
			{
				cnt_ver_p2++;
			}
			/* Look for 3 O's horizontally*/		
			else if(grid[j][i] == 'O')
			{
				cnt_hor_p2++;
			}
			printf("cnt_ver_p1 : %d\n", cnt_ver_p1);
			printf("cnt_hor_p1 : %d\n", cnt_hor_p1);
			// printf("cnt_ver_p2 : %d\n", cnt_ver_p2);
			// printf("cnt_hor_p2 : %d\n", cnt_hor_p2);
		}
		// if(cnt_p1 == 3 || cnt_p2 == 3)
		// 	break;
		//cnt_p1 = 0;
		// cnt_p2 = 0;
	}

	for(int i = 0; i < ROWS; i++)
	{

		if(grid[i][i] == 'X')
		{
			cnt_diag_p1++;
		}

		else if(grid[i][2-i] == 'X')
		{
			cnt_diag_p1++;
		}

		if(grid[i][i] == 'O')
		{
			cnt_diag_p2++;
		}
		else if(grid[i][2-i] == 'O')
		{
			cnt_diag_p2++;
		}

	}

	if((cnt_ver_p1 == 3) || (cnt_hor_p1 == 3) || (cnt_diag_p1 == 3))
	{
		return 1;
	}
	else if((cnt_ver_p2 == 3) || (cnt_hor_p2) || (cnt_diag_p2 == 3))
	{
		return 2;
	}
}



