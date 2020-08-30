#pragma once
class Cinterface
{
public:
	void system_exit();     //退出系统
	void clearall();		//清空
	void erase(int, int, int, int);	//擦除
	void setframe(int, int, int, int);  //画方框
	void gotoxy(int x, int y);   //定位光标
	Cinterface();
	virtual ~Cinterface();
};

