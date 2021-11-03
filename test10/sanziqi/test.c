#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//测试三子棋游戏
void meun() {
	printf("******************\n");
	printf("*** 1.开始游戏 ***\n");
	printf("*** 0.退出游戏 ***\n");
	printf("******************\n");
}

//游戏的完整算法
void game() {
	char ret = 0;
	//数组存放棋盘的信息
	char board[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n"); 
	}
}
void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meun();
		printf("请选择：\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
int main() {
	test();
	return 0;
}