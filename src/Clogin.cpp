#include "pch.h"
#include "Clogin.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include "Cmyexception.h"
#include <conio.h>
#define WAIT 1    //��½�ȴ�����
using namespace std;


char original_username[]="Rick";          //�û���
char original_userpassword[]="123456";    //����

void c_stdin()                            //��ջ�����
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
	successornot = true;      //�ж��Ƿ��½�ɹ�
}

Clogin::~Clogin()
{
	delete[]username;
	delete[]userpassword;

}
 
void Clogin::login_interface()     //��½����
{
	setframe(1, 1, 40, 20);
	gotoxy(11, 5);
	cout << "��ӭʹ��ѧ������ϵͳ";
	setframe(11, 8, 20, 7);
	gotoxy(12, 10);
	cout << "�û�����";
	gotoxy(12, 12);
	cout << "���룺";
	gotoxy(31, 18);
	cout << "�˳�-e";
	gotoxy(22, 18);
	cout << "����-i";

}

void Clogin::login_input()     //�����û���������
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

void Clogin::login_state()    //��½״̬
{
	if (!strcmp(username, original_username) && !strcmp(userpassword, original_userpassword))
	{
		gotoxy(11, 16);
		cout << "��½�ɹ���load...";
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
		cout << "�û��������벻��ȷ��";
		Sleep(2000);
		erase(11, 16, 20, 1);
		erase(20, 10, strlen(username), 1);
		erase(18, 12, strlen(userpassword), 1);
		gotoxy(50, 30);
	}
}

bool Clogin::return_suc()     //�жϵ�½�Ƿ�ɹ�
{
	return successornot;
}
