#pragma once
#include "Cinterface.h"
class Cstudent_interface : public Cinterface
{
public:
	void functionpage();             
	Cstudent_interface();							//功能页
	virtual ~Cstudent_interface();
	void return_bottom(int locx,int locy);          //返回键
	void continue_bottom(int locx,int locy);		//继续键
	void nextpage_bottom(int locx,int locy);		//下一页
	void lastpage_bottom(int locx,int locy);		//上一页
	void score_bottom(int locx, int locy);			//展示成绩总体情况
	void rank_bottom(int locx, int locy);			//等级键
	void scoreinfo_bottom(int locx, int locy);		//展示分数段键
	void visual_pagenum(int locx, int locy, int page, int totalpage);    //显示页数
};

