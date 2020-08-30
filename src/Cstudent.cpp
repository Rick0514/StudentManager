#include "pch.h"
#include "Cstudent.h"
#include "Cinterface.h"
#include <iomanip>

Cstudent::Cstudent()
{
	stu_college = 0;
	stu_name = 0;
}

Cstudent::~Cstudent()
{
	delete[]stu_college;
	delete[]stu_name;
}

istream& operator>>(istream& input, Cstudent &c)
{
	try
	{
		Cinterface ctemp;
		Cmyexception etemp;

		ctemp.gotoxy(5, 5);
		cout << "学生姓名：";
		ctemp.gotoxy(5, 7);
		cout << "学生学号：";
		ctemp.gotoxy(5, 9);
		cout << "学生年龄：";
		ctemp.gotoxy(5, 11);
		cout << "学生学院：";
		ctemp.gotoxy(5, 13);
		cout << "数学成绩：";
		ctemp.gotoxy(5, 15);
		cout << "C++成绩：";
		ctemp.gotoxy(5, 17);
		cout << "英语成绩：";
		
		ctemp.gotoxy(15,5);
		etemp.check_memory(c.stu_name);
		c.stu_name = new char[10];
		input.get(c.stu_name, 10);
		input.clear();
		input.ignore(100, '\n');

		ctemp.gotoxy(15, 7);
		input >> c.stu_id;
		input.clear();
		input.ignore(100, '\n');
		
		ctemp.gotoxy(15, 9);
		input >> c.stu_age;
		input.clear();
		input.ignore(100, '\n');

		ctemp.gotoxy(15, 11);
		etemp.check_memory(c.stu_college);
		c.stu_college = new char[10];
		input.get(c.stu_college, 10);
		input.clear();
		input.ignore(100, '\n');

		ctemp.gotoxy(15, 13);
		input >> c.stu_math;
		input.clear();
		input.ignore(100, '\n');

		ctemp.gotoxy(15, 15);
		input >> c.stu_cpp;
		input.clear();
		input.ignore(100, '\n');

		ctemp.gotoxy(15, 17);
		input >> c.stu_english;
		input.clear();
		input.ignore(100, '\n');

		c.stu_sum=c.stu_math+c.stu_cpp+c.stu_english;
		c.stu_av = 1.0*c.stu_sum / 3;
	}
	catch (char* e)
	{
		if (!strcmp(e, "memory"))	cerr << "memory error!";
	}
	return input;
}

void Cstudent::display_stuinfo(int locx,int locy)
{
	// TODO: 在此处添加实现代码.
	int wid=12;
	Cinterface c;
	c.gotoxy(locx, locy);
	cout << stu_id;
	c.gotoxy(locx + wid, locy);
	cout << stu_name;
	c.gotoxy(locx + wid*2, locy);
	cout << stu_age; 
	c.gotoxy(locx + wid*3, locy);
	cout << stu_college;
	c.gotoxy(locx + wid*4, locy);
	cout << stu_math;
	c.gotoxy(locx + wid*5, locy);
	cout << stu_cpp;
	c.gotoxy(locx + wid*6-1, locy);
	cout << stu_english;
}

void Cstudent::add_studentinfo()
{
	// TODO: 在此处添加实现代码.
	Cinterface c;
	c.clearall();
	c.setframe(1,1,40,20);
	c.gotoxy(5, 3);
	cout << "请输入添加学生信息";
	cin >> *this;
}


void Cstudent::display_sturank(int locx, int locy)
{
	// TODO: 在此处添加实现代码.
	int wid = 15;
	Cinterface c;
	c.gotoxy(locx, locy);
	cout << setiosflags(ios::fixed)<<setiosflags(ios::left) ;
	cout << setw(wid) << setprecision(2) << stu_id;
	cout << setw(wid) << setprecision(2) << stu_name;
    cout << setw(wid) << setprecision(2) << stu_sum;
	cout << setw(wid) << setprecision(2) << return_rank();
}


char Cstudent::return_rank()
{
	// TODO: 在此处添加实现代码.
	if (stu_av >= 90)
	{
		return 'A';
	}
	else if (stu_av < 90 && stu_av >= 80)
	{
		return 'B';

	}
	else if (stu_av < 80 && stu_av >= 60)
	{
		return 'C';
	}
	else if (stu_av < 60)
	{
		return 'D';
	}
}