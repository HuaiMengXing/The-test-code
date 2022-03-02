#include<iostream>
#include<sstream>
#include<fstream>
#include"Student.h"
#include"teacher.h"
#include"manager.h"
#include"Identity.h"
#include"globalFile.h"
using namespace std;

//��¼����
void LoginIn(string filename, int type)
{
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id ;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2 )
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����";
	cin >> name;

	cout << "���������룺";
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;
		string fName;
		string fPwd;

		while (ifs>>fId && ifs>>fName && ifs>>fPwd)
		{
			cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;
			cout << "ѧ����¼�ɹ�" << endl;
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����¼�ɹ�" << endl;
				system("pause");
				system("cls");
				//person = new Student(id, name, pwd);

				//����ѧ����ݵ��Ӳ˵�

			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
	}
	else if (type == 3)
	{
		//����Ա�����֤
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select;

	while (true)
	{
		cout << "* ****************************************** *" << endl;
		cout << "             1��ѧ �� �� ��                   " << endl;
		cout << "                                              " << endl;
		cout << "             2���� ʦ �� ��                   " << endl;
		cout << "                                              " << endl;
		cout << "             3����  ��  Ա                    " << endl;
		cout << "                                              " << endl;
		cout << "             0����      ��                    " << endl;
		cout << "* ****************************************** *" << endl;

		cout << "���������ѡ��";
		cin >> select;

		switch (select)
		{
		case 1://ѧ������
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ����
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
