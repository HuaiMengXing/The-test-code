#include"WorkerManager.h"
WorkerManager::WorkerManager()
{
	int num = this->get_EmpNum();//��ȡ�ļ����ж�������
	this->m_enpNum = num;//��ֵ���ռ�����
	if (num==0)
	{
		this->m_fileIsEmpty = true;
	}

	this->m_enpArray = new Worker * [this->m_enpNum];//���������ȡ�ļ��е�����
	this->init_Emp();//��ȡ
}

WorkerManager::~WorkerManager()
{
	if (this->m_enpArray!=NULL)//�ͷ����У������Ѿ��������ļ���
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
	cout << "* ************************************ְ������ϵͳ************************************ *" << endl;
	cout << "                     1-����ְ����Ϣ  2-��ʾְ����Ϣ  3-ɾ��ְ����Ϣ                   "   << endl;
	cout << "            4-����ְ����Ϣ 5-����ְ����Ϣ           6-���� 8-��� 9-�˳�                " << endl;
	cout << "* ************************************************************************************ *" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_emp()//��ӹ���
{
	cout << "��������ӵ�������";
	int addNum = 0;
	cin >> addNum;
	if (addNum>0)
	{
		int newsize = this->m_enpNum + addNum;//�¿ռ��С����ԭ���Ŀռ�����+����ӵ�����
		Worker**newSpace = new Worker* [newsize];//����һ���ռ�
		if (this->m_enpArray!=NULL)//���ļ��л�ȡ�����ݿ������¿ռ�
		{
			for (int i = 0; i < this->m_enpNum; i++)
			{
				newSpace[i] = this->m_enpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;
			string sex;
			int dSelect;//����ѡ��

			cout << "�������" << i+1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i+1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������" << i+1 << "����ְ���Ա�" << endl;
			cin >> sex;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cout << "��ѡ���ְ����λ��" << endl;
			cin >> dSelect;
			
			Worker* worker = NULL;		
			switch (dSelect)
			{
			case 1:worker = new Employee(id, name, sex, 1001);//������
				break;
			case 2:worker = new Manager(id, name, sex, 2001);//������
				break;
			case 3:worker = new Boss(id, name, sex, 3001);//������
				break;

			default:
				break;
			}
			newSpace[this->m_enpNum + i] = worker;//������ӵ����ݸ�ֵ���ļ��л�ȡ�����ݺ���
		}
		delete[] this->m_enpArray;//�ͷ�ԭ���Ŀռ�	
		this->m_enpArray = newSpace;//���¿ռ�ָ��
		this->m_enpNum = newsize;//��������

		this->save();//�������ݵ��ļ�
		this->m_fileIsEmpty = false;//�ļ���Ϊ��

		cout << "�ɹ����" << addNum << "��ְ��" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()//�ļ�����
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

void WorkerManager::show()//��ʾ
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "ְ������Ϊ��" << this->m_enpNum << endl;
	for (int i = 0; i < this->m_enpNum; i++)
	{
		cout <<"��ţ�" << this->m_enpArray[i]->m_ID << "  "
			<< "������" << this->m_enpArray[i]->m_Name << "  "
			<< "�Ա�" << this->m_enpArray[i]->m_Sex << "  "
			<< "��λ��" << this->m_enpArray[i]->getDeptName() << "  "
			<< "���ű�ţ�" << this->m_enpArray[i]->m_DeptID << endl;

	}
	system("pause");
	system("cls");
}

int WorkerManager::get_EmpNum()//��ȡ����
{
	fstream fs;
	string str;
	int num = 0;
	fs.open(filename, ios::in);
	while (getline(fs, str))//ÿһ�в鿴
	{
		num++;
	}
	fs.close();
	return num;
}

void WorkerManager::init_Emp()//���ļ������ݶ�ȡ����
{
	fstream fs;
	fs.open(filename, ios::in);

	int id ;//ְ�����
	string name;
	string sex;
	string str;
	int did;//���ű��

	int index=0;
	while (fs>>id && fs>>name && fs>>sex && fs>>str && fs>>did)
	{
		Worker* worker = NULL;//������
		if (did==1001)
		{
			worker= new Employee(id, name, sex, did);//������
		}
		else if (did == 2001)
		{
			worker = new Manager(id, name, sex, did);//������
		}
		else if (did == 3001)
		{
			worker = new Boss(id, name, sex, did);//������
		}
		this->m_enpArray[index] = worker;//��ֵ���Ѿ����ٵ�����
		index++;
	}
	fs.close();

}

int WorkerManager::IsExist(int id)//�ж�ְ���Ƿ����	
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
		cout << "������" << endl;
	}
	return index;
}

void WorkerManager::Del_emp()//ɾ��ְ��
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "��������Ҫɾ����ְ����ţ�";
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);//��

		if (index)
		{
			if (this->m_enpNum==1)//���ֻ��һ������ֱ�Ӹ�ֵΪHULL
			{
				this->m_enpArray = NULL;
			}
			else if(index==this->m_enpNum-1)//���һ���������һ����ֵΪ��
			{
				this->m_enpArray[index] = NULL;
			}
			for (int i = index; i < this->m_enpNum-1; i++)//һ��һ���ĸ�����ȥ
			{
				this->m_enpArray[i] = this->m_enpArray[i + 1];
			}
			this->m_enpNum--;//���¿ռ�����
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}	
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_emp()//��������
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
	   cout << "��������Ҫ���ĵ�ְ����ţ�";
	   int id = 0;
	   cin >> id;

	   int index = this->IsExist(id);//��
	   cout << &this->m_enpArray[index] << endl;

	   if (index)
	   {
		   int Id;//ְ�����
		   string name;
		   string sex;
		   int dSelect;//����ѡ��

		   cout << "��������ְ����ţ�" << endl;
		   cin >> Id;
		   cout << "��������ְ��������" << endl;
		   cin >> name;
		   cout << "��������ְ���Ա�" << endl;
		   cin >> sex;
		   cout << "1.��ͨԱ��" << endl;
		   cout << "2.����" << endl;
		   cout << "3.�ܲ�" << endl;
		   cout << "��ѡ���ְ����λ��" << endl;
		   cin >> dSelect;

		   Worker* worker = NULL;
		   switch (dSelect)
		   {
		   case 1:worker = new Employee(Id, name, sex, 1001);//������
			   break;
		   case 2:worker = new Manager(Id, name, sex, 2001);//������
			   break;
		   case 3:worker = new Boss(Id, name, sex, 3001);//������
			   break;

		   default:
			   break;
		   }
		   cout << &worker << endl;
		   this->m_enpArray[index] = worker;
		   cout << &this->m_enpArray[index] << endl;
		   this->save();
		   cout << "���ĳɹ�" << endl;
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
	  if (this->m_enpArray != NULL)//�ͷ�
	  {
		for (int i = 0; i < this->m_enpNum; i++)//�ͷ��������������
		{
			delete this->m_enpArray[i];
			this->m_enpArray[i] = NULL;
		}
		delete[] this->m_enpArray;//�ͷ�����
		this->m_enpArray = NULL;
		this->m_enpNum = 0;
		this->m_fileIsEmpty = true;
	    cout << "��ճɹ�" << endl;
	  }
	}
	system("pause");
	system("cls");
}
