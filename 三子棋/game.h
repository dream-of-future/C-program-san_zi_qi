#ifndef _GAME_H_
#define _GAME_H_
#define COL 3
#define ROW 3
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
void initchessboard(char board[ROW][COL], int row, int col);
void chessboard(char board[ROW][COL], int row, int col);
void playchess1(char board[ROW][COL], int row, int col);
void playchess2(char board[ROW][COL], int row, int col);
void AI_cheess(char board[ROW][COL], int row, int col);
char isfull(char board[ROW][COL], int row, int col);
char judges3(char board[ROW][COL], int row, int col);
//char judges3_AI(char board[ROW][COL], int row, int col);
#endif _GAME_H_