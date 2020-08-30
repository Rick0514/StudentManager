#pragma once
#include <iostream>
#include "Cmyexception.h"
using namespace std;

class Cstudent
{
public:
	Cstudent();
	virtual ~Cstudent();
	friend istream& operator>>(istream &input, Cstudent &c);
	friend class Cstulist;
	void display_stuinfo(int locx, int locy);        //展示学生信息页面
	void add_studentinfo();                         //添加学生信息页面
	void display_sturank(int locx, int locy);       //展示学生等级页面   
	char return_rank();                             //返回学生等级
protected:
	double stu_english;
	double stu_cpp;
	double stu_math;
	char* stu_college;
	int stu_age;
	long int stu_id;
	double stu_av;       //学生各科平均成绩
	double stu_sum;      //学生总分
	char* stu_name;

};

