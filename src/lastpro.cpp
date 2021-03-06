// lastpro.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include "Cinterface.h"
#include "Clogin.h"
#include <conio.h>
#include "Cstudent_interface.h"
#include "Cstudent.h"
#include <stdio.h>
#include "Cstulist.h"
using namespace std;

void clear_stdin()  //清空缓冲区
{
	while (_kbhit())
	{
		_getch();
	}
}

int main()
{
	
	Clogin c;					//创建登陆页面对象c
	c.login_interface();
	char ch;
	c.gotoxy(50, 30);
	while (c.return_suc())		//登陆
	{
		ch = _getch();
		switch (ch)
		{
		case 'i':	c.login_input(); break;
		case 'e':	c.system_exit();
		}
	}

	Cstudent_interface cs_i;			//创建系统页面对象cs_i
	cs_i.functionpage();
	Cstulist cslist;
	clear_stdin();  //清空缓冲区
	

	while (true)
	{
		c.gotoxy(50,30);
		ch = _getch();
		clear_stdin();
		switch (ch)
		{
			case 'a':   //添加学生信息
			{
				bool judge1 = true;

				while (judge1)
				{
					cslist.add_student();
					cs_i.return_bottom(33,19);
					cs_i.continue_bottom(25,19);
					bool judge2 = true;
					while (judge2)
					{
						c.gotoxy(50, 30);
						ch = _getch();
						clear_stdin();
						if (ch == 'c')
						{
							judge2 = false;
						}
						else if (ch == 'b')
						{
							c.clearall();
							cs_i.functionpage();
							judge1 = false;
							judge2 = false;
						}
					}
				}
				break;
			}
			case 'z':	//展示学生信息
			{
				cslist.page1();
				cslist.display_student();
				cs_i.return_bottom(81, 19);
				cs_i.nextpage_bottom(68, 19);
				cs_i.lastpage_bottom(55,19);
				cs_i.score_bottom(36,19);
				cs_i.rank_bottom(25, 19);
				cs_i.visual_pagenum(3, 19, cslist.list_page(), (cslist.list_length()/14+1));
				while (true)
				{
					ch = _getch();
					clear_stdin();

					if (ch == 'b')
					{
						c.clearall();
						cs_i.functionpage();
						break;
					}
					if (ch == 'n'&&cslist.list_page() <= (cslist.list_length() / 14))
					{
						cslist.changepage(1);
						cslist.display_student();
						cs_i.return_bottom(81, 19);
						cs_i.nextpage_bottom(68, 19);
						cs_i.lastpage_bottom(55, 19);
						cs_i.score_bottom(36, 19);
						cs_i.rank_bottom(25, 19);
						cs_i.visual_pagenum(3, 19, cslist.list_page(), (cslist.list_length() / 14 + 1));
					}
					if (ch == 'l'&&cslist.list_page() > 1)
					{
						cslist.changepage(0);
						cslist.display_student();
						cs_i.return_bottom(81, 19);
						cs_i.nextpage_bottom(68, 19);
						cs_i.lastpage_bottom(55, 19);
						cs_i.score_bottom(36, 19);
						cs_i.rank_bottom(25, 19);
						cs_i.visual_pagenum(3, 19, cslist.list_page(), (cslist.list_length() / 14 + 1));
					}
					if (ch == 's')
					{
						cslist.show_score();
						cs_i.return_bottom(25,19);
						cs_i.scoreinfo_bottom(12, 19);
						while (true)
						{
							ch = _getch();
							clear_stdin();
							if (ch == 'b')
							{
								c.clearall();
								cslist.page1();
								cslist.display_student();
								cs_i.return_bottom(81, 19);
								cs_i.nextpage_bottom(68, 19);
								cs_i.lastpage_bottom(55, 19);
								cs_i.score_bottom(36, 19);
								cs_i.rank_bottom(25, 19);
								cs_i.visual_pagenum(3, 19, cslist.list_page(), (cslist.list_length() / 14 + 1));
								break;
							}
							if (ch == 'f')
							{
								cslist.score_info();
								cs_i.return_bottom(58, 24);
								while (true)
								{
									ch = _getch();
									clear_stdin();
									if (ch == 'b')
									{
										cslist.show_score();
										cs_i.return_bottom(25, 19);
										cs_i.scoreinfo_bottom(12, 19);
										break;
									}
								}

							}
						}
					}
					if (ch == 'r')
					{
						cslist.rpage1();
						cslist.display_studentrank();
						cs_i.return_bottom(61, 19);
						cs_i.nextpage_bottom(48, 19);
						cs_i.lastpage_bottom(35, 19);
						cs_i.visual_pagenum(3, 19, cslist.list_rpage(), (cslist.list_length() / 14 + 1));
						while (true)
						{
							ch = _getch();
							clear_stdin();
							if (ch == 'b')
							{
								c.clearall();
								cslist.page1();
								cslist.display_student();
								cs_i.return_bottom(81, 19);
								cs_i.nextpage_bottom(68, 19);
								cs_i.lastpage_bottom(55, 19);
								cs_i.score_bottom(36, 19);
								cs_i.rank_bottom(25, 19);
								cs_i.visual_pagenum(3, 19, cslist.list_page(), (cslist.list_length() / 14 + 1));
								break;
							}
							if (ch == 'n'&&cslist.list_rpage() <= (cslist.list_length() / 14))
							{
								
								cslist.changerpage(1);
								cslist.display_studentrank();
								cs_i.return_bottom(61, 19);
								cs_i.nextpage_bottom(48, 19);
								cs_i.lastpage_bottom(35, 19);
								cs_i.visual_pagenum(3, 19, cslist.list_rpage(), (cslist.list_length() / 14 + 1));
							}
							if (ch == 'l'&&cslist.list_rpage() > 1)
							{
								cslist.changerpage(0);
								cslist.display_studentrank();
								cs_i.return_bottom(61, 19);
								cs_i.nextpage_bottom(48, 19);
								cs_i.lastpage_bottom(35, 19);
								cs_i.visual_pagenum(3, 19, cslist.list_rpage(), (cslist.list_length() / 14 + 1));
							}
						}
					}
				

				}
				break;
			}
			case 'c':   //查询学生信息
			{
				cslist.check_student();
				cs_i.continue_bottom(68,19);
				cs_i.return_bottom(81, 19);
				while (true)
				{
					ch = _getch();
					clear_stdin();
					if (ch == 'c')
					{
						cslist.check_student();
						cs_i.continue_bottom(68, 19);
						cs_i.return_bottom(81, 19);
					}
					else if (ch == 'b')
					{
						c.clearall();
						cs_i.functionpage();
						break;
					}
				}
				break;
			}
			case 'i':   //插入学生信息
			{
				cslist.insert_student(); 
				cs_i.continue_bottom(25, 19);
				cs_i.return_bottom(33, 19);
				while (true)
				{
					ch = _getch();
					clear_stdin();
					if (ch == 'c')
					{
						cslist.insert_student();
						cs_i.continue_bottom(25, 19);
						cs_i.return_bottom(33, 19);
					}
					else if (ch == 'b')
					{
						c.clearall();
						cs_i.functionpage();
						break;
					}
				}
				break;
			}        
			case 'd': //删除学生信息
			{
				cslist.delete_student();
				cs_i.continue_bottom(25, 19);
				cs_i.return_bottom(33, 19);
				while (true)
				{
					ch = _getch();
					clear_stdin();
					if (ch == 'c')
					{
						cslist.delete_student();
						cs_i.continue_bottom(25, 19);
						cs_i.return_bottom(33, 19);
					}
					else if(ch == 'b')
					{
						c.clearall();
						cs_i.functionpage();
						break;
					}
				}
				break;
			}
			case 'w':  //写入学生信息
			{
				cslist.write_student();
				cs_i.continue_bottom(25, 19);
				cs_i.return_bottom(33, 19);
				while (true)
				{
					ch = _getch();
					clear_stdin();
					if (ch == 'c')
					{
						cslist.write_student();
						cs_i.continue_bottom(25, 19);
						cs_i.return_bottom(33, 19);
					}
					else if (ch == 'b')
					{
						c.clearall();
						cs_i.functionpage();
						break;
					}
				}
				break;

			}
			case 'r':  //读入学生信息 
			{
				cslist.read_student();
				cs_i.continue_bottom(25, 19);
				cs_i.return_bottom(33, 19);
				while (true)
				{
					ch = _getch();
					clear_stdin();
					if (ch == 'c')
					{
						cslist.read_student();
						cs_i.continue_bottom(25, 19);
						cs_i.return_bottom(33, 19);
					}
					else if (ch == 'b')
					{
						c.clearall();
						cs_i.functionpage();
						break;
					}
				}
				break;
			}
			case 'x':  //修改学生信息
			{
				cslist.change_student();
				cs_i.continue_bottom(25, 19);
				cs_i.return_bottom(33, 19);
				while (true)
				{
					ch = _getch();
					clear_stdin();
					if (ch == 'c')
					{
						cslist.change_student();
						cs_i.continue_bottom(25, 19);
						cs_i.return_bottom(33, 19);
					}
					else if (ch == 'b')
					{
						c.clearall();
						cs_i.functionpage();
						break;
					}
				}
				break;

			}
			case 'e':	c.system_exit(); break;

		}
	}
	c.gotoxy(50, 30);
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
