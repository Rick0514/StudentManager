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
	// TODO: �ڴ˴����ʵ�ִ���.

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
	pTemp->pNext = 0;//���ָ����

	len++;

}


void Cstulist::display_student()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Cinterface c;
	c.clearall();
	c.setframe(1, 1, 91, 20);
	c.gotoxy(7, 2);
	cout << "ѧ��ѧ��    ";
	cout << "ѧ������    ";
	cout << "ѧ������    ";
	cout << "ѧ��ѧԺ    ";
	cout << "��ѧ�ɼ�    ";
	cout << "c++�ɼ�    ";
	cout << "Ӣ��ɼ�    ";

	Cstulist *ph = pHead;    //��ʽͷ��

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
	// TODO: �ڴ˴����ʵ�ִ���.
	Cinterface c;
	c.clearall();
	c.setframe(1,1,91,20);
	c.gotoxy(5,3);
	cout << "����������Ҫ��ѯ��ѧ��������";
	char* pname = new char[10];
	cin.get(pname,10);
	cin.clear();
	cin.ignore(10, '\n');

	Cstulist *pTemp=pHead;
	if (pHead == 0)
	{
		c.gotoxy(5, 5);
		cout << "�Ҳ�����ѧ����";
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
				cout << "�ҵ���ѧ����";
				c.gotoxy(7, 7);
				cout << "ѧ��ѧ��    ";
				cout << "ѧ������    ";
				cout << "ѧ������    ";
				cout << "ѧ��ѧԺ    ";
				cout << "��ѧ�ɼ�    ";
				cout << "c++�ɼ�    ";
				cout << "Ӣ��ɼ�    ";
				pTemp->st.display_stuinfo(7, 8);
				break;
			}
			pTemp = pTemp->pNext;
			
			
		} 
		if (strcmp(pTemp->st.stu_name,pname)==0)
		{
			judge = true;
			c.gotoxy(5, 5);
			cout << "�ҵ���ѧ����";
			c.gotoxy(7, 7);
			cout << "ѧ��ѧ��    ";
			cout << "ѧ������    ";
			cout << "ѧ������    ";
			cout << "ѧ��ѧԺ    ";
			cout << "��ѧ�ɼ�    ";
			cout << "c++�ɼ�    ";
			cout << "Ӣ��ɼ�    ";
			pTemp->st.display_stuinfo(7, 8);

		}

		if(!judge)
		{
			c.gotoxy(5, 5);
			cout << "�Ҳ�����ѧ����";
		}

	}
	delete[]pname;
	
}


void Cstulist::insert_student()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	try
	{
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1,1,40,20);
		c.gotoxy(5,3);
		cout << "���������ѧ��λ�ã���壩��";
		int loc;
		bool judge;
		cin >> loc;
		judge = cin.fail();
		cin.clear();
		cin.ignore(100, '\n');
		e.check_input(judge);
		
		e.check_loc(loc, len);
		//��ʼ����
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
			cerr << "����λ�ò����ڣ�";
			Sleep(1000);
		}
		if (strcmp(pe, "in") == 0)
		{
			c.gotoxy(5, 5);
			cerr << "���벻�Ϸ���";
			Sleep(1000);
		}
	}
	

}


void Cstulist::delete_student()
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
		cout << "������Ҫɾ��ѧ����������";
		char* pname = new char[10];
		cin.get(pname,10);
		cin.clear();
		cin.ignore(10, '\n');
		
		//��������
		
		bool judge = false;
		int count = 0;
		
		while (pTemp)
		{
			if (strcmp(pTemp->st.stu_name, pname) == 0)
			{
				judge = true;
				c.gotoxy(5, 5);
				cout << "ɾ���ɹ���";
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
				p = p->pNext;    //pTemp��ǰһ��
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
			cerr << "��ѧ������ϵͳ�ڣ�";
			Sleep(1000);	
		}
		if (strcmp(pe, "no") == 0)
		{
			c.gotoxy(5, 5);
			cerr << "��ǰϵͳû��ѧ����";
		}
	}
	
}


void Cstulist::write_student()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	try
	{
		char* filename = new char[30];
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1, 1, 40, 20);
		c.gotoxy(5, 3);
		cout << "������Ҫ������ļ�����";
		c.gotoxy(5,4);
		cin >> filename;
		
		
		ofstream outfile;
		outfile.open(filename, ios::out|ios::binary);
		e.check_ofile(outfile);
		int wid1 = 15;
		int wid2 = 19;
		outfile << setiosflags(ios::left);
		outfile << setw(wid1)<<"ѧ��ѧ��";
		outfile << setw(wid1)<<"ѧ������";
		outfile << setw(wid1)<<"ѧ������";
		outfile << setw(wid1)<<"ѧ��ѧԺ";
		outfile << setw(wid1)<<"��ѧ�ɼ�";
		outfile << setw(wid1)<<"c++�ɼ�";
		outfile << setw(wid1)<<"Ӣ��ɼ�";
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
		cout << "д���ļ��ɹ���";		
		outfile.close();
		delete[]filename;
	}
	catch (const char* pe)
	{
		Cinterface c;
		if (strcmp(pe, "file") == 0)
		{
			c.gotoxy(5, 6);
			cerr << "�ļ���ʧ��";
			Sleep(1000);
		}
	}
	
}


void Cstulist::read_student()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	try
	{
		char* filename = new char[30];  //�����ļ���
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1, 1, 40, 20);
		c.gotoxy(5, 3);
		cout << "������Ҫ������ļ�����";
		c.gotoxy(5, 4);
		cin >> filename;

		ifstream infile;
		infile.open(filename,ios::in|ios::binary);
		e.check_ifile(infile);
		

		infile.seekg(0, ios::beg); //ָ�����
		char s[200];
		infile.getline(s, 200);   //��ȥ����

		Cstulist *pTemp = pHead;
		
		if (pHead)   //�������ݣ����ں���׷��
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
		cout << "�����ļ��ɹ���";
		infile.close();


	}
	catch (const char* pe)
	{
		Cinterface c;
		if (strcmp(pe, "file") == 0)
		{
			c.gotoxy(5, 6);
			cerr << "�ļ���ʧ��";
			Sleep(1000);
		}
	}
}


void Cstulist::change_student()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	try
	{
		Cinterface c;
		Cmyexception e;
		c.clearall();
		c.setframe(1, 1, 40, 20);
		c.gotoxy(5, 3);
		cout << "�������޸�ѧ��λ�ã�";
		int loc;
		bool judge;
		cin >> loc;
		judge = cin.fail();
		cin.clear();
		cin.ignore(50, '\n');
		e.check_input(judge);
		e.check_change(loc, len);
		//��ʼ����
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
			cerr << "�޸�ѧ�������ڣ�";
			Sleep(1000);
		}
		if (strcmp(pe, "in") == 0)
		{
			c.gotoxy(5, 5);
			cerr << "���벻�Ϸ���";
			Sleep(1000);
		}
	}
}


int Cstulist::list_length()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return len;
}


int Cstulist::list_page()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return page;
}


void Cstulist::changepage(bool j)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
	// TODO: �ڴ˴����ʵ�ִ���.
	page = 1;
}


double Cstulist::average(int cho)   //ѡ��1.��ѧ��2.c++��3.Ӣ��
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
	// TODO: �ڴ˴����ʵ�ִ���.
	Cinterface c;
	c.clearall();
	c.setframe(1,1,36,20);
	
	if (len == 0)
	{
		c.gotoxy(13, 5);
		cout << "ϵͳ����ѧ����";
	}
	else 
	{
		c.gotoxy(4, 4);
		cout << "��������" << len;
		c.gotoxy(4,6);
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << "��ѧƽ���֣�" << average(1);
		c.gotoxy(4, 8);
		cout << "c++ƽ���֣�" << average(2); 
		c.gotoxy(4, 10);
		cout << "Ӣ��ƽ���֣�" << average(3);
		c.gotoxy(4, 12);
		cout << "��ѧ��������" << int(good_rate(1, 1)) << "�ˣ������ʣ�" << good_rate(1, 0);
		c.gotoxy(4, 14);
		cout << "c++��������" << int(good_rate(2, 1)) << "�ˣ������ʣ�" << good_rate(2, 0);
		c.gotoxy(4, 16);
		cout << "Ӣ�Ｐ������" << int(good_rate(3, 1)) << "�ˣ������ʣ�" << good_rate(3, 0);
	}
	
}

double Cstulist::good_rate(int cho1,int cho2)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
	// TODO: �ڴ˴����ʵ�ִ���.
	Cinterface c;
	c.clearall();
	c.setframe(1, 1, 71, 20);
	c.gotoxy(5, 2);
	int wid = 15;
	cout << setiosflags(ios::left) << setw(wid) << "ѧ��ѧ��";
	cout << setiosflags(ios::left) << setw(wid) << "ѧ������";
	cout << setiosflags(ios::left) << setw(wid) << "ѧ���ܷ�";
	cout << setiosflags(ios::left) << setw(wid) << "ѧ���ȼ�";
	
	Cstulist *ph = pHead;    //��ʽͷ��

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
	// TODO: �ڴ˴����ʵ�ִ���.
	rpage = 1;
}


int Cstulist::list_rpage()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return rpage;
}


void Cstulist::changerpage(bool j)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
	// TODO: �ڴ˴����ʵ�ִ���.
	Cinterface c;
	c.clearall();
	c.setframe(1,1,70, 25);
	c.gotoxy(5, 3);
	cout << "���Ʒ��������";
	
	c.gotoxy(5,5);
	cout << "��ѧ��";
	c.gotoxy(5, 6);
	cout << setiosflags(ios::left) << setw(8) << "90������";
	visualnum(score_infocount(1,'m'));
	c.gotoxy(5, 7);
	cout << setiosflags(ios::left) << setw(8) << "80-90��";
	visualnum(score_infocount(2, 'm'));
	c.gotoxy(5, 8);
	cout << setiosflags(ios::left) << setw(8) << "60-80��";
	visualnum(score_infocount(3, 'm'));
	c.gotoxy(5, 9);
	cout << setiosflags(ios::left) << setw(8) << "60������";
	visualnum(score_infocount(4, 'm'));


	c.gotoxy(5, 11);
	cout << "c++��";
	c.gotoxy(5, 12);
	cout << setiosflags(ios::left) << setw(8) << "90������";
	visualnum(score_infocount(1, 'c'));
	c.gotoxy(5, 13);
	cout << setiosflags(ios::left) << setw(8) << "80-90��";
	visualnum(score_infocount(2, 'c'));
	c.gotoxy(5, 14);
	cout << setiosflags(ios::left) << setw(8) << "60-80��";
	visualnum(score_infocount(3, 'c'));
	c.gotoxy(5, 15);
	cout << setiosflags(ios::left) << setw(8) << "60������";
	visualnum(score_infocount(4, 'c'));



	c.gotoxy(5, 17);
	cout << "Ӣ�";
	c.gotoxy(5, 18);
	cout << setiosflags(ios::left) << setw(8) << "90������";
	visualnum(score_infocount(1, 'e'));
	c.gotoxy(5, 19);
	cout << setiosflags(ios::left) << setw(8) << "80-90��";
	visualnum(score_infocount(2, 'e'));
	c.gotoxy(5, 20);
	cout << setiosflags(ios::left) << setw(8) << "60-80��";
	visualnum(score_infocount(3, 'e'));
	c.gotoxy(5, 21);
	cout << setiosflags(ios::left) << setw(8) << "60������";
	visualnum(score_infocount(4, 'e'));

}


int Cstulist::score_infocount(int cho, char sub)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
	// TODO: �ڴ˴����ʵ�ִ���.
	double l;
	int max = 50;
	int leng;   //���ճ���
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
	cout << " " << num << "��";
}