#include "pch.h"
#include "Cstudent_interface.h"
#include <iostream>
using namespace std;

Cstudent_interface::Cstudent_interface()
{
}


Cstudent_interface::~Cstudent_interface()
{
}

void Cstudent_interface::functionpage()     //����ҳ
{
	setframe(1, 1, 40, 20);
	gotoxy(10, 3);
	cout << "1.չʾѧ����Ϣ-z";
	gotoxy(10, 5);
	cout << "2.���ѧ����Ϣ-a";
	gotoxy(10, 7);
	cout << "2.��ѯѧ����Ϣ-c";
	gotoxy(10, 9);
	cout << "3.ɾ��ѧ����Ϣ-d";
	gotoxy(10, 11);
	cout << "4.����ѧ����Ϣ-i";
	gotoxy(10, 13);
	cout << "5.�޸�ѧ����Ϣ-x";
	gotoxy(10, 15);
	cout << "6.����ѧ����Ϣ-r";
	gotoxy(10, 17);
	cout << "7.����ѧ����Ϣ-w";
	gotoxy(33,19);
	cout << "�˳�-e";

}


void Cstudent_interface::return_bottom(int locx,int locy)     //���ؼ�
{
	// TODO: �ڴ˴����ʵ�ִ���.
	gotoxy(locx,locy);
	cout << "����-b";
}


void Cstudent_interface::continue_bottom(int locx,int locy)   //������
{
	// TODO: �ڴ˴����ʵ�ִ���.
	gotoxy(locx,locy);
	cout << "����-c";
}


void Cstudent_interface::nextpage_bottom(int locx,int locy)    //��һҳ��
{
	// TODO: �ڴ˴����ʵ�ִ���.
	gotoxy(locx,locy);
	cout << "��һҳ-n";
}


void Cstudent_interface::lastpage_bottom(int locx,int locy)    //��һҳ��
{
	// TODO: �ڴ˴����ʵ�ִ���.
	gotoxy(locx, locy);
	cout << "��һҳ-l";
}


void Cstudent_interface::score_bottom(int locx, int locy)		//�������������
{
	// TODO: �ڴ˴����ʵ�ִ���.
	gotoxy(locx, locy);
	cout << "�ɼ��������-s";
}


void Cstudent_interface::rank_bottom(int locx,int locy)			//�ȼ���
{
	// TODO: �ڴ˴����ʵ�ִ���.
	gotoxy(locx,locy);
	cout << "�ȼ�-r";
}

void Cstudent_interface::scoreinfo_bottom(int locx, int locy)		//��������Ϣ��
{
	// TODO: �ڴ˴����ʵ�ִ���.
	gotoxy(locx, locy);
	cout << "������-f";
}


void Cstudent_interface::visual_pagenum(int locx,int locy,int page,int totalpage)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	gotoxy(locx, locy);
	cout << "ҳ����" << page << "/" << totalpage;
}
