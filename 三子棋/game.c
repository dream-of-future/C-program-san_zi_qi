#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void initchessboard(char board[ROW][COL], int row, int col)
{
	int i=0,j=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void chessboard(char board[ROW][COL], int row, int col)
{
	int i=0,j=0;

	printf("   ");//标行号
	for (i = 0; i < row && i<9; i++)
	{
		printf(" %d  ", i + 1);
	}
	for (i = 9; i < row; i++)
	{
		printf(" %d ", i + 1);
	}
	printf("\n");

	for (i = 0; i < row; i++)//行
	{
		printf("%d", i+1);//标列号
		if (i+1<10)
			printf("  ");
		else if (i+1 >= 10)
			printf(" ");

		for (j = 0; j < col; j++)//列
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		
		if (i < row - 1)
		{
			printf("   ");
			for (j = 0; j < col; j++)//分割线
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void playchess1(char board[ROW][COL], int row, int col)
{
	while (1)//PLAYER 1
	{
		printf("PLAYER 1\n");
		int x=0, y=0;
		printf("请输入落子坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[y-1][x-1] == ' ')
			{
				board[y-1][x-1] = '*';
				break;
			}
			else
				printf("输入非法，请重新输入\n");
		}
		else
		{
			printf("输入非法，请重新输入\n");
		}
	}
	
}

void playchess2(char board[ROW][COL], int row, int col)
{
	while (1)//PLAYER 2
	{
		printf("PLAYER 2\n");
		int x=0, y=0;
		printf("请输入落子坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = '#';
				break;
			}
			else
				printf("输入非法，请重新输入\n");
		}
		else
		{
			printf("输入非法，请重新输入\n");
		}
	}
}

void AI_cheess(char board[ROW][COL], int row, int col)
{
	int i = 0;
	while (1)
	{
		int x = 0;
		int y = 0;
		//printf("AI\n");
		x = rand() % col;
		y = rand() % row;
		if (x+1 >= 1 && x+1 <= row && y+1 >= 1 && y+1 <= col)
		{
			if (board[y][x] == ' ')
			{
				board[y][x] = '#';
				break;
			}
			else
				i++;
			//printf("输入非法，请重新输入");
		}
		else
		{
			i++;
			printf("输入非法，请重新输入\n");
		}
		if (i > 100)
		{
			printf("对方认输\n");
			exit(1);
		}
	}
}

//void judges3(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	int n_a = 0;
//	int n_b = 0;
//	int n_c = 0;
//	int a = strcmp(board[i][i], board[i + 1][i + 1]);
//	int b = strcmp(board[i][j], board[i][j + 1]);
//	int c = strcmp(board[i][j], board[i + 1][j]);
//	for (i = 0; i < row-1; i++)
//	{
//		if (a==0 && board[i][i]!=' ')
//		{
//			n_a++;
//			if (n_a = 2)
//			{
//				printf("WIN");
//				exit(1);
//			}
//		}
//
//		for (j = 0; j < row - 1; j++)
//		{
//			if (b==0 && board[i][j] != ' ')
//			{
//				n_b++;
//				if (n_b = 2)
//				{
//					printf("WIN");
//					exit(1);
//				}
//
//			}
//
//			else if (c==0&& board[i][j] != ' ')
//			{
//				n_c++;
//				if (n_c = 2)
//				{
//					printf("WIN");
//					exit(1);
//				}
//
//			}
//		}
//	}
//}

char isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int n = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				n++;
			}
		}
	}

	if (n == 9)
	{
		return '1';
	}
	return '0';
}


char judges3(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	for (i = 0; i < col; i++)//列
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	
	if (board[1][1] == board[0][0] && board[1][1] == board[2][2] && board[0][0] != ' ')//主对角线
	{
		return board[0][0];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')//副对角线
	{
		return board[0][2];
	}
	
	return isfull(board, ROW, COL);
}

