#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Cmyexception
{
public:
	void check_memory(char*);           //����ڴ�
	Cmyexception();
	virtual ~Cmyexception();
	void check_loc(int ,int );          //���λ��
	void check_ofile(ofstream &);       //�������ļ���
	void check_ifile(ifstream &);       //��������ļ���
	void check_change(int loc,int len); //����޸���Ϣ
	void check_input(bool);             //���������Ϣ
};

