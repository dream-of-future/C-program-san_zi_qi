#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
#include "game.h"
#include <stdlib.h>

void win_AI(char ret)
{
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}

	else if (ret == '#')
	{
		printf("AIӮ\n");
	}

	else
	{
		printf("ƽ��\n");
	}
}

void win(char ret)
{
	if (ret == '*')
	{
		printf("Ӯ��:���1\n");
	}

	else if (ret == '#')
	{
		printf("Ӯ��:���2\n");
	}

	else
	{
		printf("ƽ��\n");
	}
}

void menu_1()
{
	printf("**************************\n");
	printf("** 1.play ***** 0.exit ***\n");
	printf("**************************\n");
	printf("��ѡ��:");
}

void menu_2()
{
	printf("********************************************************\n");
	printf("*** 1.˫�˶�ս   2.�˻���ս(��)   3.�˻���ս(һ��) ***\n");
	printf("********************************************************\n");
	printf("��ѡ��:");
}

void menu_3()
{
	
	printf("**********************************************\n");
	printf("***                �Ƿ����                ***\n");
	printf("*** 1.����                          0.�˳� ***\n");
	printf("**********************************************\n");
	printf("��ѡ��:");
}

void game()//˫��
{
	char ret='0';
	char board[ROW][COL];
	initchessboard(board, ROW, COL);//��ʼ������
	chessboard(board, ROW, COL);//��ӡ����
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

void game2_1()//�˻�
{
	char ret='0';
	char board[ROW][COL];
	initchessboard(board, ROW, COL);//��ʼ������
	chessboard(board, ROW, COL);//��ӡ����

	while (1)
	{
		playchess1(board, ROW, COL);//���
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

void game2_2()//�˻�
{
	char ret = '0';
	char board[ROW][COL]={0,0,0,0,0,0,0,0,0};
	initchessboard(board, ROW, COL);//��ʼ������
	chessboard(board, ROW, COL);//��ӡ����

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

		playchess1(board, ROW, COL);//���
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
				printf("�����˳�");
				exit(1);
			default:
				printf("����������\n");
			}
		} while (i);
		menu_1();
		scanf("%d",&n);
	} while (n != 0);
	
	return 0;
}