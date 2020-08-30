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
	void display_stuinfo(int locx, int locy);        //չʾѧ����Ϣҳ��
	void add_studentinfo();                         //���ѧ����Ϣҳ��
	void display_sturank(int locx, int locy);       //չʾѧ���ȼ�ҳ��   
	char return_rank();                             //����ѧ���ȼ�
protected:
	double stu_english;
	double stu_cpp;
	double stu_math;
	char* stu_college;
	int stu_age;
	long int stu_id;
	double stu_av;       //ѧ������ƽ���ɼ�
	double stu_sum;      //ѧ���ܷ�
	char* stu_name;

};

