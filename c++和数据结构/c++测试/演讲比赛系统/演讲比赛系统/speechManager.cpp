#include"speechMAnager.h"

SpeechManager::SpeechManager()
{
	//��ʼ��
	this->initSpeech();

	//����12��ѡ��
	this->createSpeaker();

}

//�˵�����
void SpeechManager::show_Menu()
{
	cout << "********************************************************" << endl;
	cout << "                  1.��ʼ�ݽ�����" << endl;
	cout << "                  2.�鿴�����¼" << endl;
	cout << "                  3.��ձ�����¼" << endl;
	cout << "                  0.�˳���������" << endl;
	cout << "********************************************************" << endl;
	cout << endl;
}

//��ʼ����
void SpeechManager::startSpeech()
{
	//��һ�ֱ���

	//1.��ǩ
	speechDraw();

	//2.����
	speechContest();

	//3.��ʾ�������
	showScore();

	//�ڶ��ֿ�ʼ����
	this->m_Index++;

	//1.��ǩ
	speechDraw();

	//2.����
	speechContest();

	//3.��ʾ�����
	showScore();

	//4.�������ݵ��ļ���
	saveRecore();

	//��ʼ��
	this->initSpeech();

	//����12��ѡ��
	this->createSpeaker();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

void print(int number)
{
	cout << number << "  ";
}


//��ǩ
void SpeechManager::speechDraw()
{
	cout << "��<<" << this->m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳������" << endl;

	if (this->m_Index==1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for_each(v1.begin(), v1.end(), print);
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for_each(v2.begin(), v2.end(), print);
		cout << endl;
	}

	cout << "------------------------------------" << endl;
	system("pause");
}
//����
void SpeechManager::speechContest()
{
	cout << "----------��" << this->m_Index << "�ֱ�����ʽ��ʼ-----------" << endl;

	//��ʱ������ ���С��ɼ�
	multimap<double, int, greater<double>>groupScore;//�Զ����greater��Ҫ�ӣ���

	int num = 0;//��¼��Ա����

	vector<int>v_Src;
	if (this->m_Index==1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.f;
			//cout << score << "  ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());//����
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(),0.0);
		double avg = sum / (double)d.size();//ƽ����

		//��ӡƽ����
		//cout << "��ţ�" << *it << "  ������" << this->m_Speaker[*it].m_Name << "  ƽ���֣�" << avg << endl;

		//��ƽ���ַ��뵽map��
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//���������� ���뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it));//key�Ƿ���
		//ÿ6����ȡ��ǰ3��
		if (num%6==0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << "  ������" << this->m_Speaker[it->second].m_Name << "  �ɼ���" 
					 << this->m_Speaker[it->second].m_Score[this->m_Index-1] << endl;
			}

			int count = 0;//�ж�ǰ3��
			//ȡ��ǰ����
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3;count++, it++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vVictory.push_back(it->second);
				}
			}

			groupScore.clear();
			cout << endl;
		}
	}
	cout << "----------��" << this->m_Index << "�ֱ������-------------" << endl;
	system("pause");
}
//3.��ʾ�������
void SpeechManager::showScore()
{
	cout << "----------��" << this->m_Index << "�ֽ������-------------" << endl;
	vector<int>v;
	if (this->m_Index==1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << "  ������" << this->m_Speaker[*it].m_Name << "  �÷֣�"
			<< this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

	this->show_Menu();
}
//�����¼
void SpeechManager::saveRecore()
{
	ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);//

	if (!ofs.is_open())
	{
		cout << "û�д򿪳ɹ�!" << endl;
		system("pause");
		exit(0);
	}
	//��ÿ��ѡ�ֵ����� �����ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," <<this->m_Speaker[*it].m_Name<< "," << this->m_Speaker[*it].m_Score[1] << ",";//�������ֿ�
	}
	ofs << endl;

	ofs.close();
	cout << "��¼�Ѿ��������" << endl;

	//�ļ���Ϊ��
	this->fileIsEmpty = false;
}
//��ȡ��¼
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�ļ���յ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	
	ifs.putback(ch);//�ù��ص���һλ���Ż�ȥ

	string data;
	int index = 1;

	while (ifs>>data)
	{
		vector<string>v;

		int pos = -1;//�鵽������λ��
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);//û���ҵ��᷵��-1
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
			//cout << data << endl;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
	/*for (map<int,vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << " " << it->second[0] <<" " << it->second[1] << " " << it->second[2] << endl;
	}*/
}


//��ʾ�����¼
void SpeechManager::showRecord()
{
	//���������¼
	this->loadRecord();

	if (this->fileIsEmpty)
	{
		cout << "û�������¼��" << endl;
	}
	else
	{
		for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
		{
			cout << "��" << it->first << "��  " << "�ھ���ţ�" << it->second[0] << "  ������" << it->second[1] << "  ������ " << it->second[2] << endl
				<< "       " << "�Ǿ���ţ�" << it->second[3] << "  ������" << it->second[4] << "  ������ " << it->second[5] << endl
				<< "       " << "������ţ�" << it->second[6] << "  ������" << it->second[7] << "  ������ " << it->second[8] << endl;
			cout << endl;
		}
	}

	system("pause");
	system("cls");
}

//��չ���
void SpeechManager::clearRecord()
{
	cout << "�����Ƿ�Ҫ������У�" << endl;
	cout << " 1����" << endl;
	cout << " 2����" << endl;


	int select = 0;

	cin >> select;

	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.clear();

		//��ʼ��
		this->initSpeech();

		//����12��ѡ��
		this->createSpeaker();

		cout << "��ճɹ�!" << endl;
	}

	system("pause");
	system("cls");
}

//�˳�����
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//����12��ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ��
		this->v1.push_back(i + 10001);

		//ѡ�ֵı���Լ���Ӧ��ѡ�ַ���
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ��
void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	this->m_Index = 1;

	this->m_Record.clear();
}

SpeechManager::~SpeechManager()
{

}