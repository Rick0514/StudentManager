#pragma once
#include "Cstudent.h"
class Cstulist
{
public:
	Cstulist();
	virtual ~Cstulist();
	void add_student();
protected:
	Cstudent st;  //数据域
	Cstulist *pHead;
	Cstulist *pNext;
	int len;		//列表成员个数
	int page;		//页数	
	int rpage;      //页数
public:
	void display_student();     //展示学生信息
	void check_student();		//查找学生信息
	void insert_student();		//插入学生信息
	void delete_student();		//删除学生信息
	void write_student();		//导出学生信息
	void read_student();		//读入学生信息
	void change_student();		//修改学生信息
	int list_length();			//返回链表长度
	int list_page();			//返回页数
	void changepage(bool);		//翻页
	void page1();
	double average(int cho);	//返回平均分
	void show_score();			//展示成绩总体情况
	double good_rate(int cho1, int cho2);//显示及格率
	void display_studentrank(); //展示学生等级
	void rpage1();
	int list_rpage();
	void changerpage(bool);
	void score_info();			
	int score_infocount(int cho, char sub);  //返回各分数段人数
	void visualnum(int num);		//可视化各分数段
};

