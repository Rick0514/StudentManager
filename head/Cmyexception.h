#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Cmyexception
{
public:
	void check_memory(char*);           //检查内存
	Cmyexception();
	virtual ~Cmyexception();
	void check_loc(int ,int );          //检查位置
	void check_ofile(ofstream &);       //检查输出文件流
	void check_ifile(ifstream &);       //检查输入文件流
	void check_change(int loc,int len); //检查修改信息
	void check_input(bool);             //检查输入信息
};

