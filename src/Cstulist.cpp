#include "pch.h"
#include "Cstulist.h"
#include "Cinterface.h"
#include "Cmyexception.h"
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <math.h>

Cstulist::Cstulist()
{
	Cstudent st;
	pHead = 0;
	pNext = 0;
	len = 0;
	page = 1;
	rpage = 1;
	
}

Cstulist::~Cstulist()
{
	delete pHead;
	delete pNext;
}


void Cstulist::add_student()
{
	// TODO: 在此处添加实现代码.

	Cstulist *pNew = new Cstulist;
	pNew->st.add_studentinfo();

	Cstulist *pTemp=pHead;
	if (pHead == 0)
	{
		pHead = pNew;
	}
	else
	{
		while (pTemp->pNext)
		{
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = pNew;
		 
	}
	pTemp = pNew;
	pTemp->pNext = 0;//清空指针域

	len++;

}


void Cstulist::display_student()
{
	// TODO: 在此处添加实现代码.
	Cinterface c;
	c.clearall();
	c.setframe(1, 1, 91, 20);
	c.gotoxy(7, 2);
	cout << "学生学号    ";
	cout << "学生姓名    ";
	cout << "学生年龄    ";
	cout << "学生学院    ";
	cout << "数学成绩    ";
	cout << "c++成绩    ";
	cout << "英语成绩    ";

	Cstulist *ph = pHead;    //形式头部

	for (int i = 0; i < (page - 1) * 14-1; i++)
	{
		ph = ph->pNext;
	}

	Cstulist *pTemp;
	if (ph&&page>1)
	{
		pTemp = ph->pNext;
	}
	else
	{
		pTemp = ph;
	}

	for (int i = 1; i<=14&&pTemp; i++)
	{
		pTemp->st.display_stuinfo(7,2+i);
		pTemp = pTemp->pNext;
	}
}

void Cstulist::check_student()
{
	// TODO: 在此处添加实现代码.
	Cinterface c;
	c.clearall();
	c.setframe(1,1,91,20);
	c.gotoxy(5,3);
	cout << "请输入你所要查询的学生姓名：";
	char* pname = new char[10];
	cin.get(pname,10);
	cin.clear();
	cin.ignore(10, '\n');

	Cstulist *pTemp=pHead;
	if (pHead == 0)
	{
		c.gotoxy(5, 5);
		cout << "找不到该学生！";
	}
	else
	{
		bool judge=false;
		while (pTemp->pNext)
		{
			if (strcmp(pTemp->st.stu_name, pname) == 0)
			{
				judge = true;
				c.gotoxy(5, 5);
				cout << "找到此学生！";
				c.gotoxy(7, 7);
				cout << "学生学号    ";
				cout << "学生姓名    ";
				cout << "学生年龄    ";
				cout << "学生学院    ";
				cout << "数学成绩    ";
				cout << "c++成绩    ";
				cout << "英语成绩    ";
				pTemp->st.display_stuinfo(7, 8);
				break;
			}
			pTemp = pTemp->pNext;
			
			
		} 
		if (strcmp(pTemp->st.stu_name,pname)==0)
		{
			judge = true;
			c.gotoxy(5, 5);
			cout << "找到此学生！";
			c.gotoxy(7, 7);
			cout << "学生学号    ";
			cout << "学生姓名    ";
			cout << "学生年龄    ";
			cout << "学生学院    ";
			cout << "数学成绩    ";
			cout << "c++成绩    ";
			cout << "英语成绩    ";
			pTemp->st.display_stuinfo(7, 8);

		}

		if(!judge)
		{
			c.gotoxy(5, 5);
			cout << "找不到该学生！";
		}

	}
	delete[]pname;
	
}


void Cstulist::insert_student()
{
	// TODO: 在此处添加实现代码.
	try
	{
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1,1,40,20);
		c.gotoxy(5,3);
		cout << "请输入插入学生位置（后插）：";
		int loc;
		bool judge;
		cin >> loc;
		judge = cin.fail();
		cin.clear();
		cin.ignore(100, '\n');
		e.check_input(judge);
		
		e.check_loc(loc, len);
		//开始插入
		len++;
		Cstulist *pTemp = pHead;
		Cstulist *pNew = new Cstulist;

		if (loc)
		{
			for (int i = 0; i < loc-1; i++)
			{
				pTemp = pTemp->pNext;
			}
			cin >> pNew->st;
		
			pNew->pNext = pTemp->pNext;
			pTemp->pNext = pNew;

		}
		else
		{
			cin >> pNew->st;
			pNew->pNext = pHead;
			pHead = pNew;
		}
		
		
	}
	catch (const char* pe)
	{
		Cinterface c;
		if (strcmp(pe, "loc")==0)
		{
			c.gotoxy(5,5);
			cerr << "插入位置不存在！";
			Sleep(1000);
		}
		if (strcmp(pe, "in") == 0)
		{
			c.gotoxy(5, 5);
			cerr << "输入不合法！";
			Sleep(1000);
		}
	}
	

}


void Cstulist::delete_student()
{
	// TODO: 在此处添加实现代码.
	try
	{
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1, 1, 40, 20);
		c.gotoxy(3, 3);
		Cstulist *pTemp = pHead;
		Cstulist *p = pHead;
		if (pTemp == 0)
		{
			throw "no";
		}
		cout << "请输入要删除学生的姓名：";
		char* pname = new char[10];
		cin.get(pname,10);
		cin.clear();
		cin.ignore(10, '\n');
		
		//遍历查找
		
		bool judge = false;
		int count = 0;
		
		while (pTemp)
		{
			if (strcmp(pTemp->st.stu_name, pname) == 0)
			{
				judge = true;
				c.gotoxy(5, 5);
				cout << "删除成功！";
				if (len == 1)
				{
					pHead = 0;
					break;
				}
				else if(count == 0)
				{
					pHead = pHead->pNext;
				}
				else
				{
					p->pNext = pTemp->pNext;
					break;
				}
				
			}
			pTemp = pTemp->pNext;
			if (count)
			{
				p = p->pNext;    //pTemp的前一个
			}
			count++;
		}
		if (!judge)	throw "none";
		
		delete[]pname;

	}
	catch (const char* pe)
	{
		Cinterface c;
		if (strcmp(pe, "none") == 0)
		{
			c.gotoxy(5, 5);
			cerr << "此学生不在系统内！";
			Sleep(1000);	
		}
		if (strcmp(pe, "no") == 0)
		{
			c.gotoxy(5, 5);
			cerr << "当前系统没有学生！";
		}
	}
	
}


void Cstulist::write_student()
{
	// TODO: 在此处添加实现代码.
	try
	{
		char* filename = new char[30];
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1, 1, 40, 20);
		c.gotoxy(5, 3);
		cout << "请输入要输出的文件名：";
		c.gotoxy(5,4);
		cin >> filename;
		
		
		ofstream outfile;
		outfile.open(filename, ios::out|ios::binary);
		e.check_ofile(outfile);
		int wid1 = 15;
		int wid2 = 19;
		outfile << setiosflags(ios::left);
		outfile << setw(wid1)<<"学生学号";
		outfile << setw(wid1)<<"学生姓名";
		outfile << setw(wid1)<<"学生年龄";
		outfile << setw(wid1)<<"学生学院";
		outfile << setw(wid1)<<"数学成绩";
		outfile << setw(wid1)<<"c++成绩";
		outfile << setw(wid1)<<"英语成绩";
		outfile << "\r\n";
	
		Cstulist *pTemp = pHead;
		while (pTemp)
		{
			outfile << setiosflags(ios::left);
			outfile << setw(wid2) << pTemp->st.stu_id;
			outfile << setw(wid2) << pTemp->st.stu_name;
			outfile << setw(wid2) << pTemp->st.stu_age;
			outfile << setw(wid2) << pTemp->st.stu_college;
			outfile << setw(wid2) << pTemp->st.stu_math;
			outfile << setw(wid2) <<pTemp->st.stu_cpp;
			outfile << setw(wid2) <<pTemp->st.stu_english;
			if (pTemp->pNext)
			{
				outfile << "\r\n";
			}
			pTemp = pTemp->pNext;
		}

		c.gotoxy(5, 6);
		cout << "写入文件成功！";		
		outfile.close();
		delete[]filename;
	}
	catch (const char* pe)
	{
		Cinterface c;
		if (strcmp(pe, "file") == 0)
		{
			c.gotoxy(5, 6);
			cerr << "文件打开失败";
			Sleep(1000);
		}
	}
	
}


void Cstulist::read_student()
{
	// TODO: 在此处添加实现代码.
	try
	{
		char* filename = new char[30];  //读入文件名
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1, 1, 40, 20);
		c.gotoxy(5, 3);
		cout << "请输入要读入的文件名：";
		c.gotoxy(5, 4);
		cin >> filename;

		ifstream infile;
		infile.open(filename,ios::in|ios::binary);
		e.check_ifile(infile);
		

		infile.seekg(0, ios::beg); //指针归零
		char s[200];
		infile.getline(s, 200);   //除去首行

		Cstulist *pTemp = pHead;
		
		if (pHead)   //已有内容，则在后面追加
		{
			while (pTemp->pNext)
			{
				pTemp = pTemp->pNext;
			}
		}
		while (!infile.eof())
		{
			Cstulist *pNew = new Cstulist;

			pNew->st.stu_name = new char[10];
			pNew->st.stu_college = new char[30];

			infile >> pNew->st.stu_id >> pNew->st.stu_name >> pNew->st.stu_age >> pNew->st.stu_college >> pNew->st.stu_math >> pNew->st.stu_cpp >> pNew->st.stu_english;
			pNew->st.stu_sum = pNew->st.stu_math + pNew->st.stu_cpp + pNew->st.stu_english;
			pNew->st.stu_av = 1.0*pNew->st.stu_sum / 3;


			if (pNew->st.stu_id == 0)
			{
				infile.close();
				delete pNew;
				break;
			}
	
			if (pTemp)
			{
				pTemp->pNext = pNew;
				pTemp = pNew;
				pTemp->pNext = 0;
			}
			else
			{
				pHead = pNew;
				pTemp = pHead;
			}
			len++;

		}
		cin.clear();
		cin.ignore(100, '\n');
		c.gotoxy(5, 6);
		cout << "读入文件成功！";
		infile.close();


	}
	catch (const char* pe)
	{
		Cinterface c;
		if (strcmp(pe, "file") == 0)
		{
			c.gotoxy(5, 6);
			cerr << "文件打开失败";
			Sleep(1000);
		}
	}
}


void Cstulist::change_student()
{
	// TODO: 在此处添加实现代码.
	try
	{
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1, 1, 40, 20);
		c.gotoxy(5, 3);
		cout << "请输入修改学生位置：";
		int loc;
		bool judge;
		cin >> loc;
		judge = cin.fail();
		cin.clear();
		cin.ignore(50, '\n');
		e.check_input(judge);
		e.check_change(loc, len);
		//开始插入
		Cstulist *pTemp = pHead;
		Cstulist *p = pHead;
		Cstulist *pNew = new Cstulist;

		if (loc == 1)
		{
			pNew->st.add_studentinfo();
			pHead = pNew;
			pHead->pNext=pTemp->pNext;
		}
		else
		{
			for (int i = 0; i < loc-1; i++)
			{
				if (i == 0)
				{
					pTemp = pTemp->pNext;
				}
				else
				{
					pTemp = pTemp->pNext;
					p = p->pNext;
				}
			}
			cin >> pNew->st;
			p->pNext = pNew;
			p = pNew;
			p->pNext = pTemp->pNext;
		}

	}
	catch (const char* pe)
	{
		Cinterface c;
		if (strcmp(pe, "no") == 0)
		{
			c.gotoxy(5, 5);
			cerr << "修改学生不存在！";
			Sleep(1000);
		}
		if (strcmp(pe, "in") == 0)
		{
			c.gotoxy(5, 5);
			cerr << "输入不合法！";
			Sleep(1000);
		}
	}
}


int Cstulist::list_length()
{
	// TODO: 在此处添加实现代码.
	return len;
}


int Cstulist::list_page()
{
	// TODO: 在此处添加实现代码.
	return page;
}


void Cstulist::changepage(bool j)
{
	// TODO: 在此处添加实现代码.
	if (j)
	{
		page++;
	}
	else
	{
		page--;
	}
}


void Cstulist::page1()
{
	// TODO: 在此处添加实现代码.
	page = 1;
}


double Cstulist::average(int cho)   //选择：1.数学，2.c++，3.英语
{
	// TODO: 在此处添加实现代码.
	Cstulist *pTemp = pHead;
	double sum=0;
	switch (cho)
	{
		case 1:
		{
			while (pTemp)
			{
				sum = sum + pTemp->st.stu_math;
				pTemp = pTemp->pNext;
			}
			return sum / len;
		}
		case 2:
		{
			while (pTemp)
			{
				sum = sum + pTemp->st.stu_cpp;
				pTemp = pTemp->pNext;
			}
			return sum / len;
		}
		case 3:
		{
			while (pTemp)
			{
				sum = sum + pTemp->st.stu_english;
				pTemp = pTemp->pNext;
			}
			return 1.0*sum / len;
		}
	}

}


void Cstulist::show_score()
{
	// TODO: 在此处添加实现代码.
	Cinterface c;
	c.clearall();
	c.setframe(1,1,36,20);
	
	if (len == 0)
	{
		c.gotoxy(13, 5);
		cout << "系统内无学生！";
	}
	else 
	{
		c.gotoxy(4, 4);
		cout << "总人数：" << len;
		c.gotoxy(4,6);
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << "数学平均分：" << average(1);
		c.gotoxy(4, 8);
		cout << "c++平均分：" << average(2); 
		c.gotoxy(4, 10);
		cout << "英语平均分：" << average(3);
		c.gotoxy(4, 12);
		cout << "数学及格人数" << int(good_rate(1, 1)) << "人，及格率：" << good_rate(1, 0);
		c.gotoxy(4, 14);
		cout << "c++及格人数" << int(good_rate(2, 1)) << "人，及格率：" << good_rate(2, 0);
		c.gotoxy(4, 16);
		cout << "英语及格人数" << int(good_rate(3, 1)) << "人，及格率：" << good_rate(3, 0);
	}
	
}

double Cstulist::good_rate(int cho1,int cho2)
{
	// TODO: 在此处添加实现代码.
	Cstulist *pTemp = pHead;
	int sum=0;
	switch (cho1)
	{
		case 1:
		{
			while (pTemp)
			{
				if (pTemp->st.stu_math >= 60)
				{
					sum++;
				}
				pTemp = pTemp->pNext;
			}
			break;
		}
		case 2:
		{
			while (pTemp)
			{
				if (pTemp->st.stu_cpp >= 60)
				{
					sum++;
				}
				pTemp = pTemp->pNext;
			}
			break;
		}
		case 3:
		{
			while (pTemp)
			{
				if (pTemp->st.stu_english >= 60)
				{
					sum++;
				}
				pTemp = pTemp->pNext;
			}
			break;
		}
	}
		
	if (cho2)
	{
		return sum;
	}
	else
	{
		return 1.0*sum / len;
	}
}


void Cstulist::display_studentrank()
{
	// TODO: 在此处添加实现代码.
	Cinterface c;
	c.clearall();
	c.setframe(1, 1, 71, 20);
	c.gotoxy(5, 2);
	int wid = 15;
	cout << setiosflags(ios::left) << setw(wid) << "学生学号";
	cout << setiosflags(ios::left) << setw(wid) << "学生姓名";
	cout << setiosflags(ios::left) << setw(wid) << "学生总分";
	cout << setiosflags(ios::left) << setw(wid) << "学生等级";
	
	Cstulist *ph = pHead;    //形式头部

	for (int i = 0; i < (rpage - 1) * 14 - 1; i++)
	{
		ph = ph->pNext;
	}



	Cstulist *pTemp;
	if (ph&&rpage > 1)
	{
		pTemp = ph->pNext;
	}
	else
	{
		pTemp = ph;
	}


	for (int i = 1; i <= 14 && pTemp; i++)
	{
		pTemp->st.display_sturank(7, 2 + i);
		pTemp = pTemp->pNext;
	}


}


void Cstulist::rpage1()
{
	// TODO: 在此处添加实现代码.
	rpage = 1;
}


int Cstulist::list_rpage()
{
	// TODO: 在此处添加实现代码.
	return rpage;
}


void Cstulist::changerpage(bool j)
{
	// TODO: 在此处添加实现代码.
	if (j)
	{
		rpage++;
	}
	else
	{
		rpage--;
	}
}


void Cstulist::score_info()
{
	// TODO: 在此处添加实现代码.
	Cinterface c;
	c.clearall();
	c.setframe(1,1,70, 25);
	c.gotoxy(5, 3);
	cout << "各科分数段情况";
	
	c.gotoxy(5,5);
	cout << "数学：";
	c.gotoxy(5, 6);
	cout << setiosflags(ios::left) << setw(8) << "90分以上";
	visualnum(score_infocount(1,'m'));
	c.gotoxy(5, 7);
	cout << setiosflags(ios::left) << setw(8) << "80-90分";
	visualnum(score_infocount(2, 'm'));
	c.gotoxy(5, 8);
	cout << setiosflags(ios::left) << setw(8) << "60-80分";
	visualnum(score_infocount(3, 'm'));
	c.gotoxy(5, 9);
	cout << setiosflags(ios::left) << setw(8) << "60分以下";
	visualnum(score_infocount(4, 'm'));


	c.gotoxy(5, 11);
	cout << "c++：";
	c.gotoxy(5, 12);
	cout << setiosflags(ios::left) << setw(8) << "90分以上";
	visualnum(score_infocount(1, 'c'));
	c.gotoxy(5, 13);
	cout << setiosflags(ios::left) << setw(8) << "80-90分";
	visualnum(score_infocount(2, 'c'));
	c.gotoxy(5, 14);
	cout << setiosflags(ios::left) << setw(8) << "60-80分";
	visualnum(score_infocount(3, 'c'));
	c.gotoxy(5, 15);
	cout << setiosflags(ios::left) << setw(8) << "60分以下";
	visualnum(score_infocount(4, 'c'));



	c.gotoxy(5, 17);
	cout << "英语：";
	c.gotoxy(5, 18);
	cout << setiosflags(ios::left) << setw(8) << "90分以上";
	visualnum(score_infocount(1, 'e'));
	c.gotoxy(5, 19);
	cout << setiosflags(ios::left) << setw(8) << "80-90分";
	visualnum(score_infocount(2, 'e'));
	c.gotoxy(5, 20);
	cout << setiosflags(ios::left) << setw(8) << "60-80分";
	visualnum(score_infocount(3, 'e'));
	c.gotoxy(5, 21);
	cout << setiosflags(ios::left) << setw(8) << "60分以下";
	visualnum(score_infocount(4, 'e'));

}


int Cstulist::score_infocount(int cho, char sub)
{
	// TODO: 在此处添加实现代码.
	int s90, s80, s60, sl60;
	s90 = 0;
	s80 = 0;
	s60 = 0;
	sl60 = 0;

	Cstulist *pTemp = pHead;

	if (sub == 'm')
	{
		while (pTemp)
		{
			if (pTemp->st.stu_math >= 90)
			{
				s90++;
			}
			else if (pTemp->st.stu_math < 90 && pTemp->st.stu_math >= 80)
			{
				s80++;
			}
			else if (pTemp->st.stu_math < 80 && pTemp->st.stu_math >= 60)
			{
				s60++;
			}
			else if (pTemp->st.stu_math < 60)
			{
				sl60++;
			}
			pTemp = pTemp->pNext;
			
		}
	}
	else if (sub == 'c')
	{
		while (pTemp)
		{
			if (pTemp->st.stu_cpp >= 90)
			{
				s90++;
			}
			else if (pTemp->st.stu_cpp < 90 && pTemp->st.stu_cpp >= 80)
			{
				s80++;
			}
			else if (pTemp->st.stu_cpp < 80 && pTemp->st.stu_cpp >= 60)
			{
				s60++;
			}
			else if (pTemp->st.stu_cpp < 60)
			{
				sl60++;
			}
			pTemp = pTemp->pNext;
		}
	}
	else if (sub == 'e')
	{
		while (pTemp)
		{
			if (pTemp->st.stu_english >= 90)
			{
				s90++;
			}
			else if (pTemp->st.stu_english < 90 && pTemp->st.stu_english >= 80)
			{
				s80++;
			}
			else if (pTemp->st.stu_english < 80 && pTemp->st.stu_english >= 60)
			{
				s60++;
			}
			else if (pTemp->st.stu_english < 60)
			{
				sl60++;
			}
			pTemp = pTemp->pNext;
		}
	}

	if (cho == 1)
	{
		return s90;
	}
	else if (cho == 2)
	{
		return s80;
	}
	else if (cho == 3)
	{
		return s60;
	}
	else if (cho == 4)
	{
		return sl60;
	}

}


void Cstulist::visualnum(int num)
{
	// TODO: 在此处添加实现代码.
	double l;
	int max = 50;
	int leng;   //最终长度
	l = (1.0*num / len)*max;
	leng = floor(l);
	for (int i = 0; i < leng; i++)
	{
		cout << "#";
	}
	for (int j = 0; j < max - leng; j++)
	{
		cout << " ";
	}
	cout << " " << num << "人";
}