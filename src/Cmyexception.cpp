#include "pch.h"
#include "Cmyexception.h"
#include <fstream>
#include <iostream>
using namespace std;


Cmyexception::Cmyexception()
{

}

Cmyexception::~Cmyexception()
{

}

void Cmyexception::check_memory(char* strp)
{
	if (strp) throw "memory";
}


void Cmyexception::check_loc(int loc, int len)
{
	// TODO: 在此处添加实现代码.
	if (loc<0 || loc>len)
	{
		throw "loc";
	}
}


void Cmyexception::check_ofile(ofstream& of)
{
	// TODO: 在此处添加实现代码.
	if (!of.is_open())	throw "file";
}


void Cmyexception::check_ifile(ifstream& i)
{
	// TODO: 在此处添加实现代码.
	if (!i.is_open())	throw "file";
}


void Cmyexception::check_change(int loc,int len)
{
	// TODO: 在此处添加实现代码.
	if (loc <= 0 || loc > len)	throw "no";
}


void Cmyexception::check_input(bool j)
{
	// TODO: 在此处添加实现代码.
	if (j)	throw "in";

}
