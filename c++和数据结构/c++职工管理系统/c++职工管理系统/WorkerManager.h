#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Worker.h"
#include"personnel.h"
using namespace std;
#define filename "file.dat"

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	void Show_Menu();//菜单显示
	int m_enpNum;//空间中的人数
	Worker** m_enpArray;
	int get_EmpNum();//获取数量
	bool m_fileIsEmpty;
	void init_Emp();//将文件中数据读取出来
	void save();//保存文件
	int IsExist(int id);//判断职工是否存在

	void Add_emp();//添加
    void show();//显示
	void Del_emp();//删除职工
	void Mod_emp();//更改数据
    void ExitSystem();//退出
	void clean_file();

private:

};
