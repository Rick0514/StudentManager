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

void Cstudent_interface::functionpage()     //功能页
{
	setframe(1, 1, 40, 20);
	gotoxy(10, 3);
	cout << "1.展示学生信息-z";
	gotoxy(10, 5);
	cout << "2.添加学生信息-a";
	gotoxy(10, 7);
	cout << "2.查询学生信息-c";
	gotoxy(10, 9);
	cout << "3.删除学生信息-d";
	gotoxy(10, 11);
	cout << "4.插入学生信息-i";
	gotoxy(10, 13);
	cout << "5.修改学生信息-x";
	gotoxy(10, 15);
	cout << "6.读入学生信息-r";
	gotoxy(10, 17);
	cout << "7.导出学生信息-w";
	gotoxy(33,19);
	cout << "退出-e";

}


void Cstudent_interface::return_bottom(int locx,int locy)     //返回键
{
	// TODO: 在此处添加实现代码.
	gotoxy(locx,locy);
	cout << "返回-b";
}


void Cstudent_interface::continue_bottom(int locx,int locy)   //继续键
{
	// TODO: 在此处添加实现代码.
	gotoxy(locx,locy);
	cout << "继续-c";
}


void Cstudent_interface::nextpage_bottom(int locx,int locy)    //下一页键
{
	// TODO: 在此处添加实现代码.
	gotoxy(locx,locy);
	cout << "下一页-n";
}


void Cstudent_interface::lastpage_bottom(int locx,int locy)    //上一页键
{
	// TODO: 在此处添加实现代码.
	gotoxy(locx, locy);
	cout << "上一页-l";
}


void Cstudent_interface::score_bottom(int locx, int locy)		//分数总体情况键
{
	// TODO: 在此处添加实现代码.
	gotoxy(locx, locy);
	cout << "成绩总体情况-s";
}


void Cstudent_interface::rank_bottom(int locx,int locy)			//等级键
{
	// TODO: 在此处添加实现代码.
	gotoxy(locx,locy);
	cout << "等级-r";
}

void Cstudent_interface::scoreinfo_bottom(int locx, int locy)		//分数段信息键
{
	// TODO: 在此处添加实现代码.
	gotoxy(locx, locy);
	cout << "分数段-f";
}


void Cstudent_interface::visual_pagenum(int locx,int locy,int page,int totalpage)
{
	// TODO: 在此处添加实现代码.
	gotoxy(locx, locy);
	cout << "页数：" << page << "/" << totalpage;
}
