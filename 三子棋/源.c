#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
#include "game.h"
#include <stdlib.h>

void win_AI(char ret)
{
	if (ret == '*')
	{
		printf("玩家赢\n");
	}

	else if (ret == '#')
	{
		printf("AI赢\n");
	}

	else
	{
		printf("平局\n");
	}
}

void win(char ret)
{
	if (ret == '*')
	{
		printf("赢家:玩家1\n");
	}

	else if (ret == '#')
	{
		printf("赢家:玩家2\n");
	}

	else
	{
		printf("平局\n");
	}
}

void menu_1()
{
	printf("**************************\n");
	printf("** 1.play ***** 0.exit ***\n");
	printf("**************************\n");
	printf("请选择:");
}

void menu_2()
{
	printf("********************************************************\n");
	printf("*** 1.双人对战   2.人机对战(简单)   3.人机对战(一般) ***\n");
	printf("********************************************************\n");
	printf("请选择:");
}

void menu_3()
{
	
	printf("**********************************************\n");
	printf("***                是否继续                ***\n");
	printf("*** 1.继续                          0.退出 ***\n");
	printf("**********************************************\n");
	printf("请选择:");
}

void game()//双人
{
	char ret='0';
	char board[ROW][COL];
	initchessboard(board, ROW, COL);//初始化棋盘
	chessboard(board, ROW, COL);//打印棋盘
	while (1)
	{
		playchess1(board, ROW, COL);
		system("cls");
		chessboard(board, ROW, COL);
		ret = judges3(board, ROW, COL);
		if (ret != '0')
		{
			break;
		}

		playchess2(board, ROW, COL);
		system("cls");
		chessboard(board, ROW, COL);
		ret = judges3(board, ROW, COL);
		if (ret != '0')
		{
			break;
		}
	}
	win(ret);
}

void game2_1()//人机
{
	char ret='0';
	char board[ROW][COL];
	initchessboard(board, ROW, COL);//初始化棋盘
	chessboard(board, ROW, COL);//打印棋盘

	while (1)
	{
		playchess1(board, ROW, COL);//玩家
		system("cls");
		chessboard(board, ROW, COL);
		ret = judges3(board, ROW, COL);
		if (ret != '0')
		{
			break;
		}

		AI_cheess(board, ROW, COL);//AI
		system("cls");
		chessboard(board, ROW, COL);
		ret = judges3(board, ROW, COL);
		if (ret != '0')
		{
			break;
		}
	}
	win_AI(ret);
}

void game2_2()//人机
{
	char ret = '0';
	char board[ROW][COL]={0,0,0,0,0,0,0,0,0};
	initchessboard(board, ROW, COL);//初始化棋盘
	chessboard(board, ROW, COL);//打印棋盘

	while (1)
	{
		AI_cheess(board, ROW, COL);//AI
		system("cls");
		chessboard(board, ROW, COL);
		ret = judges3(board, ROW, COL);
		if (ret != '0')
		{
			break;
		}

		playchess1(board, ROW, COL);//玩家
		system("cls");
		chessboard(board, ROW, COL);
		ret = judges3(board, ROW, COL);
		if (ret != '0')
		{
			break;
		}
		
	}
	win_AI(ret);
}

int main()	
{
	srand((unsigned int)time(NULL));
	int i=0,j=0;
	int n=0;
	do
	{
		do
		{
			menu_1();
			scanf("%d", &i);
			switch (i)
			{
			case 1:
				do
				{
					menu_2();
					scanf("%d", &j);
					switch (j)
					{
					case 1:
						game();
						break;
					case 2:
						game2_1();
						break;
					case 3:
						game2_2();
						break;
					}
				} while (j);
				break;
			case 0:
				printf("程序退出");
				exit(1);
			default:
				printf("请重新输入\n");
			}
		} while (i);
		menu_1();
		scanf("%d",&n);
	} while (n != 0);
	
	return 0;
}