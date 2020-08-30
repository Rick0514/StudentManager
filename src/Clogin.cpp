#include "pch.h"
#include "Clogin.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include "Cmyexception.h"
#include <conio.h>
#define WAIT 1    //登陆等待秒数
using namespace std;


char original_username[]="Rick";          //用户名
char original_userpassword[]="123456";    //密码

void c_stdin()                            //清空缓冲区
{
	while (_kbhit())
	{
		_getch();
	}
}

Clogin::Clogin() :Cinterface()     
{
	username = 0;
	userpassword = 0;
	successornot = true;      //判断是否登陆成功
}

Clogin::~Clogin()
{
	delete[]username;
	delete[]userpassword;

}
 
void Clogin::login_interface()     //登陆界面
{
	setframe(1, 1, 40, 20);
	gotoxy(11, 5);
	cout << "欢迎使用学生管理系统";
	setframe(11, 8, 20, 7);
	gotoxy(12, 10);
	cout << "用户名：";
	gotoxy(12, 12);
	cout << "密码：";
	gotoxy(31, 18);
	cout << "退出-e";
	gotoxy(22, 18);
	cout << "输入-i";

}

void Clogin::login_input()     //输入用户名和密码
{
	try
	{
		Cmyexception ex;
		gotoxy(20, 10);
		if (username)
		{
			delete[]username;
			username = 0;
		}
		if (userpassword)
		{
			delete[]userpassword;
			userpassword = 0;
		}
		ex.check_memory(username);
		ex.check_memory(userpassword);
		username = new char[10];
		userpassword = new char[10];
		cin.get(username, 10);
		cin.clear();
		cin.ignore(100, '\n');
		gotoxy(18, 12);
		c_stdin();
		char ch=_getch();
		c_stdin();
		int i = 0;
		while (ch!= '\r') 
		{
				userpassword[i++] = ch;
				cout << "*";
				ch = _getch();
				c_stdin();
		}
		userpassword[i] = '\0';
		login_state();
	}
	catch (char* e)
	{
		if (strcmp(e, "memory") == 0)	cerr << "memory error!";
	}
}

void Clogin::login_state()    //登陆状态
{
	if (!strcmp(username, original_username) && !strcmp(userpassword, original_userpassword))
	{
		gotoxy(11, 16);
		cout << "登陆成功，load...";
		for (int i = 3; i >= 0; i--)
		{
			cout << i;
			Sleep(WAIT*1000);
			gotoxy(28, 16);
		}
		successornot = false;
		clearall();
	}
	else
	{
		gotoxy(11, 16);
		cout << "用户名或密码不正确！";
		Sleep(2000);
		erase(11, 16, 20, 1);
		erase(20, 10, strlen(username), 1);
		erase(18, 12, strlen(userpassword), 1);
		gotoxy(50, 30);
	}
}

bool Clogin::return_suc()     //判断登陆是否成功
{
	return successornot;
}
