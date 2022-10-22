#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define High 100  // ��Ϸ����ߴ�
#define Width 100


// ȫ�ֱ���
int cells[High][Width]; // ����λ��ϸ������1����0��

//����ͼ����ĳ��򣬶�Ҫ��������Ӳ���Ĵ���� 
void gotoxy(int x, int y)//��������������
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void startup()	//���ݳ�ʼ��
{
	int i, j;
	for (i = 0; i < High; i++)
		for (j = 0; j < Width; j++)
			cells[i][j] = 1;
}

void show()	 //��ʾ����
{
	gotoxy(0, 0);	//����
	int i, j;
	for (i = 0; i < High - 1; i++) {
		for (j = 0; j < Width - 1; j++)
			if (cells[i][j] == 1)
				printf("*");	//������ϸ��
			else	//cells[i][j]==0 (����)
				printf(" ");
		printf("\n");
	}
	Sleep(50);	//ͣ��0.05�� 
}

void updateWithoutInput()
{
	int NeibourNum, NewCells[High][Width], i, j;	//��һ֡��ϸ�����
	for (i = 1; i < High - 1; i++)
	{
		for (j = 1; j < Width - 1; j++)
		{
			NeibourNum =
				cells[i - 1][j - 1]
				+ cells[i][j - 1]
				+ cells[i + 1][j - 1]
				+ cells[i - 1][j]
				+ cells[i + 1][j]
				+ cells[i - 1][j + 1]
				+ cells[i][j + 1]
				+ cells[i + 1][j + 1];
			if (NeibourNum == 3)
				NewCells[i][j] = 1;
			else if (NeibourNum == 2)
				NewCells[i][j] = cells[i][j];//ֱ�Ӹ�ֵ����
			else	// >3||<2
				NewCells[i][j] = 0;
		}
	}

	for (i = 0; i < High - 1; i++)
	{
		for (j = 0; j < Width - 1; j++)
		{
			cells[i][j] = NewCells[i][j];	//��д���� 
		}
	}
}

int main()
{
	startup();  //���ݳ�ʼ��	
	while (TRUE) //��Ϸѭ��ִ��
	{
		show();  //��ʾ����
		updateWithoutInput();
	}
}
