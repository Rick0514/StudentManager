#pragma once
#include "Cinterface.h"
class Clogin :
	public Cinterface
{
public:
	bool return_suc();          //�����Ƿ��½�ɹ�
	void login_state();			//��¼״̬
	void login_input();			//����
	void login_interface();		//��½����
	Clogin();
	virtual ~Clogin();
protected:
	bool successornot;
	char* userpassword;
	char* username;
};

