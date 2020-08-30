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
	// TODO: �ڴ˴����ʵ�ִ���.
	if (loc<0 || loc>len)
	{
		throw "loc";
	}
}


void Cmyexception::check_ofile(ofstream& of)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (!of.is_open())	throw "file";
}


void Cmyexception::check_ifile(ifstream& i)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (!i.is_open())	throw "file";
}


void Cmyexception::check_change(int loc,int len)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (loc <= 0 || loc > len)	throw "no";
}


void Cmyexception::check_input(bool j)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (j)	throw "in";

}
