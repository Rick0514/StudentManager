#pragma once
#include "Cinterface.h"
class Clogin :
	public Cinterface
{
public:
	bool return_suc();          //返回是否登陆成功
	void login_state();			//登录状态
	void login_input();			//输入
	void login_interface();		//登陆界面
	Clogin();
	virtual ~Clogin();
protected:
	bool successornot;
	char* userpassword;
	char* username;
};

