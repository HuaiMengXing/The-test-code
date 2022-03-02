#include<iostream>
#include<sstream>
#include<fstream>
#include"Student.h"
#include"teacher.h"
#include"manager.h"
#include"Identity.h"
#include"globalFile.h"
using namespace std;

//登录功能
void LoginIn(string filename, int type)
{
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id ;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2 )
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：";
	cin >> name;

	cout << "请输入密码：";
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;
		string fName;
		string fPwd;

		while (ifs>>fId && ifs>>fName && ifs>>fPwd)
		{
			cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;
			cout << "学生登录成功" << endl;
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生登录成功" << endl;
				system("pause");
				system("cls");
				//person = new Student(id, name, pwd);

				//进入学生身份的子菜单

			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
	}
	else if (type == 3)
	{
		//管理员身份验证
	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select;

	while (true)
	{
		cout << "* ****************************************** *" << endl;
		cout << "             1、学 生 代 表                   " << endl;
		cout << "                                              " << endl;
		cout << "             2、老 师 代 表                   " << endl;
		cout << "                                              " << endl;
		cout << "             3、管  理  员                    " << endl;
		cout << "                                              " << endl;
		cout << "             0、退      出                    " << endl;
		cout << "* ****************************************** *" << endl;

		cout << "请输入你的选择：";
		cin >> select;

		switch (select)
		{
		case 1://学生代表
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师代表
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
