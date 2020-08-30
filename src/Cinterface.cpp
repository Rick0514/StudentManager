#include "pch.h"
#include "Cinterface.h"
#include <iostream>
#include <windows.h>
using namespace std;

Cinterface::Cinterface()
{

}

Cinterface::~Cinterface()
{

}

void Cinterface::gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(hout, pos);
}

void Cinterface::setframe(int locx, int locy, int lenx, int leny) //the size of frame is x*y
{
	int i, j;
	gotoxy(locx, locy);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < lenx; j++)	cout << "*";
		if (i == 0)	gotoxy(locx, locy + leny - 1);
	}
	gotoxy(locx, locy);
	for (i = 0; i < leny; i++)
	{
		cout << "*";
		gotoxy(locx, locy + i + 1);
	}
	gotoxy(locx + lenx - 1, locy);
	for (j = 0; j < leny; j++)
	{
		cout << "*";
		gotoxy(locx + lenx - 1, locy + j + 1);
	}
}

void Cinterface::erase(int locx, int locy, int lenx, int leny)
{
	gotoxy(locx, locy);
	for (int i = 0; i < leny; i++)
	{
		for (int j = 0; j < lenx; j++)
		{
			cout << " ";
		}
		gotoxy(locx, locy + i + 1);
	}
}

void Cinterface::clearall()
{
	system("cls");
}

void Cinterface::system_exit()
{
	clearall();
	cout << "成功退出学生信息管理系统！" << "\n\n";
	Sleep(1000);
	exit(0);
}


