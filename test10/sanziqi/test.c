#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//������������Ϸ
void meun() {
	printf("******************\n");
	printf("*** 1.��ʼ��Ϸ ***\n");
	printf("*** 0.�˳���Ϸ ***\n");
	printf("******************\n");
}

//��Ϸ�������㷨
void game() {
	char ret = 0;
	//���������̵���Ϣ
	char board[ROW][COL] = {0};
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n"); 
	}
}
void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meun();
		printf("��ѡ��\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}
int main() {
	test();
	return 0;
}