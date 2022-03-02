#include"WorkerManager.h"
WorkerManager::WorkerManager()
{
	int num = this->get_EmpNum();//获取文件中有多少数据
	this->m_enpNum = num;//赋值给空间人数
	if (num==0)
	{
		this->m_fileIsEmpty = true;
	}

	this->m_enpArray = new Worker * [this->m_enpNum];//建立数组获取文件中的数据
	this->init_Emp();//获取
}

WorkerManager::~WorkerManager()
{
	if (this->m_enpArray!=NULL)//释放所有，数据已经保存在文件中
	{
		for (int i = 0; i < this->m_enpNum; i++)
		{
			if (this->m_enpArray[i]!=NULL)
			{
				delete this->m_enpArray[i];
				this->m_enpArray[i] = NULL;
			}
		}
		delete[] this->m_enpArray;
		this->m_enpArray = NULL;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "* ************************************职工管理系统************************************ *" << endl;
	cout << "                     1-增加职工信息  2-显示职工信息  3-删除职工信息                   "   << endl;
	cout << "            4-查找职工信息 5-更改职工信息           6-排序 8-清空 9-退出                " << endl;
	cout << "* ************************************************************************************ *" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_emp()//添加功能
{
	cout << "请输入添加的人数：";
	int addNum = 0;
	cin >> addNum;
	if (addNum>0)
	{
		int newsize = this->m_enpNum + addNum;//新空间大小等于原来的空间人数+想添加的人数
		Worker**newSpace = new Worker* [newsize];//开辟一个空间
		if (this->m_enpArray!=NULL)//从文件中获取的数据拷贝给新空间
		{
			for (int i = 0; i < this->m_enpNum; i++)
			{
				newSpace[i] = this->m_enpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;
			string sex;
			int dSelect;//部门选择

			cout << "请输入第" << i+1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i+1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请输入第" << i+1 << "个新职工性别：" << endl;
			cin >> sex;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cout << "请选择该职工岗位：" << endl;
			cin >> dSelect;
			
			Worker* worker = NULL;		
			switch (dSelect)
			{
			case 1:worker = new Employee(id, name, sex, 1001);//调用子
				break;
			case 2:worker = new Manager(id, name, sex, 2001);//调用子
				break;
			case 3:worker = new Boss(id, name, sex, 3001);//调用子
				break;

			default:
				break;
			}
			newSpace[this->m_enpNum + i] = worker;//现在添加的数据赋值在文件中获取的数据后面
		}
		delete[] this->m_enpArray;//释放原来的空间	
		this->m_enpArray = newSpace;//更新空间指向
		this->m_enpNum = newsize;//更新人数

		this->save();//保存数据到文件
		this->m_fileIsEmpty = false;//文件不为空

		cout << "成功添加" << addNum << "名职工" << endl;
	}
	else
	{
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()//文件保存
{
	fstream fs;
	fs.open(filename, ios::out);

	for (int i = 0; i < this->m_enpNum; i++)
	{
		fs << this->m_enpArray[i]->m_ID << "  "
			<< this->m_enpArray[i]->m_Name << "  "
			<< this->m_enpArray[i]->m_Sex << "  "
			<<this->m_enpArray[i]->getDeptName()<<"  "
			<< this->m_enpArray[i]->m_DeptID << endl;
	}
	fs.close();

}

void WorkerManager::show()//显示
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "职工人数为：" << this->m_enpNum << endl;
	for (int i = 0; i < this->m_enpNum; i++)
	{
		cout <<"编号：" << this->m_enpArray[i]->m_ID << "  "
			<< "姓名：" << this->m_enpArray[i]->m_Name << "  "
			<< "性别：" << this->m_enpArray[i]->m_Sex << "  "
			<< "岗位：" << this->m_enpArray[i]->getDeptName() << "  "
			<< "部门编号：" << this->m_enpArray[i]->m_DeptID << endl;

	}
	system("pause");
	system("cls");
}

int WorkerManager::get_EmpNum()//获取数量
{
	fstream fs;
	string str;
	int num = 0;
	fs.open(filename, ios::in);
	while (getline(fs, str))//每一行查看
	{
		num++;
	}
	fs.close();
	return num;
}

void WorkerManager::init_Emp()//将文件中数据读取出来
{
	fstream fs;
	fs.open(filename, ios::in);

	int id ;//职工编号
	string name;
	string sex;
	string str;
	int did;//部门编号

	int index=0;
	while (fs>>id && fs>>name && fs>>sex && fs>>str && fs>>did)
	{
		Worker* worker = NULL;//创建父
		if (did==1001)
		{
			worker= new Employee(id, name, sex, did);//调用子
		}
		else if (did == 2001)
		{
			worker = new Manager(id, name, sex, did);//调用子
		}
		else if (did == 3001)
		{
			worker = new Boss(id, name, sex, did);//调用子
		}
		this->m_enpArray[index] = worker;//赋值给已经开辟的数组
		index++;
	}
	fs.close();

}

int WorkerManager::IsExist(int id)//判断职工是否存在	
{
	int index = 0;
	for (int i = 0; i < this->m_enpNum; i++)
	{
		if (this->m_enpArray[i]->m_ID == id)
		{
			index = i;
		}
	}
	if (index==0)
	{
		cout << "不存在" << endl;
	}
	return index;
}

void WorkerManager::Del_emp()//删除职工
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "请输入想要删除的职工编号：";
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);//找

		if (index)
		{
			if (this->m_enpNum==1)//如果只有一个，则直接赋值为HULL
			{
				this->m_enpArray = NULL;
			}
			else if(index==this->m_enpNum-1)//最后一个，则最后一个赋值为空
			{
				this->m_enpArray[index] = NULL;
			}
			for (int i = index; i < this->m_enpNum-1; i++)//一个一个的覆盖上去
			{
				this->m_enpArray[i] = this->m_enpArray[i + 1];
			}
			this->m_enpNum--;//更新空间人数
			this->save();
			cout << "删除成功" << endl;
		}	
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_emp()//更改数据
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
	   cout << "请输入想要更改的职工编号：";
	   int id = 0;
	   cin >> id;

	   int index = this->IsExist(id);//找
	   cout << &this->m_enpArray[index] << endl;

	   if (index)
	   {
		   int Id;//职工编号
		   string name;
		   string sex;
		   int dSelect;//部门选择

		   cout << "请输入新职工编号：" << endl;
		   cin >> Id;
		   cout << "请输入新职工姓名：" << endl;
		   cin >> name;
		   cout << "请输入新职工性别：" << endl;
		   cin >> sex;
		   cout << "1.普通员工" << endl;
		   cout << "2.经理" << endl;
		   cout << "3.总裁" << endl;
		   cout << "请选择该职工岗位：" << endl;
		   cin >> dSelect;

		   Worker* worker = NULL;
		   switch (dSelect)
		   {
		   case 1:worker = new Employee(Id, name, sex, 1001);//调用子
			   break;
		   case 2:worker = new Manager(Id, name, sex, 2001);//调用子
			   break;
		   case 3:worker = new Boss(Id, name, sex, 3001);//调用子
			   break;

		   default:
			   break;
		   }
		   cout << &worker << endl;
		   this->m_enpArray[index] = worker;
		   cout << &this->m_enpArray[index] << endl;
		   this->save();
		   cout << "更改成功" << endl;
	   }
	}
	system("pause");
	system("cls");
}

void WorkerManager::clean_file()
{
	cout << "1 Ok" << endl;
	cout << "2 NO" << endl;

	int select = 0;
	cin >> select;

	if (select==1)
	{
		fstream fs(filename, ios::out);
			fs.close();
	  if (this->m_enpArray != NULL)//释放
	  {
		for (int i = 0; i < this->m_enpNum; i++)//释放数组里面的数据
		{
			delete this->m_enpArray[i];
			this->m_enpArray[i] = NULL;
		}
		delete[] this->m_enpArray;//释放数组
		this->m_enpArray = NULL;
		this->m_enpNum = 0;
		this->m_fileIsEmpty = true;
	    cout << "清空成功" << endl;
	  }
	}
	system("pause");
	system("cls");
}
