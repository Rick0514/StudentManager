#pragma once
#include "Cinterface.h"
class Cstudent_interface : public Cinterface
{
public:
	void functionpage();             
	Cstudent_interface();							//����ҳ
	virtual ~Cstudent_interface();
	void return_bottom(int locx,int locy);          //���ؼ�
	void continue_bottom(int locx,int locy);		//������
	void nextpage_bottom(int locx,int locy);		//��һҳ
	void lastpage_bottom(int locx,int locy);		//��һҳ
	void score_bottom(int locx, int locy);			//չʾ�ɼ��������
	void rank_bottom(int locx, int locy);			//�ȼ���
	void scoreinfo_bottom(int locx, int locy);		//չʾ�����μ�
	void visual_pagenum(int locx, int locy, int page, int totalpage);    //��ʾҳ��
};

