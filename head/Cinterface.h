#pragma once
class Cinterface
{
public:
	void system_exit();     //�˳�ϵͳ
	void clearall();		//���
	void erase(int, int, int, int);	//����
	void setframe(int, int, int, int);  //������
	void gotoxy(int x, int y);   //��λ���
	Cinterface();
	virtual ~Cinterface();
};

