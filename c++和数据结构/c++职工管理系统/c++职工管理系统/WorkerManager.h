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

	void Show_Menu();//�˵���ʾ
	int m_enpNum;//�ռ��е�����
	Worker** m_enpArray;
	int get_EmpNum();//��ȡ����
	bool m_fileIsEmpty;
	void init_Emp();//���ļ������ݶ�ȡ����
	void save();//�����ļ�
	int IsExist(int id);//�ж�ְ���Ƿ����

	void Add_emp();//���
    void show();//��ʾ
	void Del_emp();//ɾ��ְ��
	void Mod_emp();//��������
    void ExitSystem();//�˳�
	void clean_file();

private:

};
