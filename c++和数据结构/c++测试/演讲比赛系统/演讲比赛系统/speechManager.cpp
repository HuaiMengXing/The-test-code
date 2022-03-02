#include"speechMAnager.h"

SpeechManager::SpeechManager()
{
	//初始化
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();

}

//菜单功能
void SpeechManager::show_Menu()
{
	cout << "********************************************************" << endl;
	cout << "                  1.开始演讲比赛" << endl;
	cout << "                  2.查看往届记录" << endl;
	cout << "                  3.清空比赛记录" << endl;
	cout << "                  0.退出比赛程序" << endl;
	cout << "********************************************************" << endl;
	cout << endl;
}

//开始比赛
void SpeechManager::startSpeech()
{
	//第一轮比赛

	//1.抽签
	speechDraw();

	//2.比赛
	speechContest();

	//3.显示晋级结果
	showScore();

	//第二轮开始比赛
	this->m_Index++;

	//1.抽签
	speechDraw();

	//2.比赛
	speechContest();

	//3.显示最后结果
	showScore();

	//4.保存数据到文件中
	saveRecore();

	//初始化
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

void print(int number)
{
	cout << number << "  ";
}


//抽签
void SpeechManager::speechDraw()
{
	cout << "第<<" << this->m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "------------------------------------" << endl;
	cout << "抽签后演讲顺序如下" << endl;

	if (this->m_Index==1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for_each(v1.begin(), v1.end(), print);
		cout << endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for_each(v2.begin(), v2.end(), print);
		cout << endl;
	}

	cout << "------------------------------------" << endl;
	system("pause");
}
//比赛
void SpeechManager::speechContest()
{
	cout << "----------第" << this->m_Index << "轮比赛正式开始-----------" << endl;

	//临时的容器 存放小组成绩
	multimap<double, int, greater<double>>groupScore;//自定义的greater不要加（）

	int num = 0;//记录人员数量

	vector<int>v_Src;
	if (this->m_Index==1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.f;
			//cout << score << "  ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());//排序
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(),0.0);
		double avg = sum / (double)d.size();//平均分

		//打印平均分
		//cout << "编号：" << *it << "  姓名：" << this->m_Speaker[*it].m_Name << "  平均分：" << avg << endl;

		//将平均分放入到map中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将分数数据 放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));//key是分数
		//每6个人取出前3名
		if (num%6==0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << "  姓名：" << this->m_Speaker[it->second].m_Name << "  成绩：" 
					 << this->m_Speaker[it->second].m_Score[this->m_Index-1] << endl;
			}

			int count = 0;//判断前3名
			//取走前三名
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
	cout << "----------第" << this->m_Index << "轮比赛完毕-------------" << endl;
	system("pause");
}
//3.显示晋级结果
void SpeechManager::showScore()
{
	cout << "----------第" << this->m_Index << "轮晋级结果-------------" << endl;
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
		cout << "选手编号：" << *it << "  姓名：" << this->m_Speaker[*it].m_Name << "  得分："
			<< this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

	this->show_Menu();
}
//保存记录
void SpeechManager::saveRecore()
{
	ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);//

	if (!ofs.is_open())
	{
		cout << "没有打开成功!" << endl;
		system("pause");
		exit(0);
	}
	//将每个选手的数据 放入文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," <<this->m_Speaker[*it].m_Name<< "," << this->m_Speaker[*it].m_Score[1] << ",";//“，”分开
	}
	ofs << endl;

	ofs.close();
	cout << "记录已经保存好了" << endl;

	//文件不为空
	this->fileIsEmpty = false;
}
//读取记录
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件清空的情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		//cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	
	ifs.putback(ch);//让光标回到第一位，放回去

	string data;
	int index = 1;

	while (ifs>>data)
	{
		vector<string>v;

		int pos = -1;//查到“，”位置
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);//没有找到会返回-1
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


//显示往届记录
void SpeechManager::showRecord()
{
	//加载往届记录
	this->loadRecord();

	if (this->fileIsEmpty)
	{
		cout << "没有往届记录！" << endl;
	}
	else
	{
		for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
		{
			cout << "第" << it->first << "届  " << "冠军编号：" << it->second[0] << "  姓名：" << it->second[1] << "  分数： " << it->second[2] << endl
				<< "       " << "亚军编号：" << it->second[3] << "  姓名：" << it->second[4] << "  分数： " << it->second[5] << endl
				<< "       " << "季军编号：" << it->second[6] << "  姓名：" << it->second[7] << "  分数： " << it->second[8] << endl;
			cout << endl;
		}
	}

	system("pause");
	system("cls");
}

//清空功能
void SpeechManager::clearRecord()
{
	cout << "请问是否要清空所有：" << endl;
	cout << " 1、是" << endl;
	cout << " 2、否" << endl;


	int select = 0;

	cin >> select;

	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.clear();

		//初始化
		this->initSpeech();

		//创建12名选手
		this->createSpeaker();

		cout << "清空成功!" << endl;
	}

	system("pause");
	system("cls");
}

//退出功能
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//创建12名选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建选手编号
		this->v1.push_back(i + 10001);

		//选手的编号以及对应的选手放入
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//初始化
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