#pragma once
#include "Cstudent.h"
class Cstulist
{
public:
	Cstulist();
	virtual ~Cstulist();
	void add_student();
protected:
	Cstudent st;  //������
	Cstulist *pHead;
	Cstulist *pNext;
	int len;		//�б��Ա����
	int page;		//ҳ��	
	int rpage;      //ҳ��
public:
	void display_student();     //չʾѧ����Ϣ
	void check_student();		//����ѧ����Ϣ
	void insert_student();		//����ѧ����Ϣ
	void delete_student();		//ɾ��ѧ����Ϣ
	void write_student();		//����ѧ����Ϣ
	void read_student();		//����ѧ����Ϣ
	void change_student();		//�޸�ѧ����Ϣ
	int list_length();			//����������
	int list_page();			//����ҳ��
	void changepage(bool);		//��ҳ
	void page1();
	double average(int cho);	//����ƽ����
	void show_score();			//չʾ�ɼ��������
	double good_rate(int cho1, int cho2);//��ʾ������
	void display_studentrank(); //չʾѧ���ȼ�
	void rpage1();
	int list_rpage();
	void changerpage(bool);
	void score_info();			
	int score_infocount(int cho, char sub);  //���ظ�����������
	void visualnum(int num);		//���ӻ���������
};

