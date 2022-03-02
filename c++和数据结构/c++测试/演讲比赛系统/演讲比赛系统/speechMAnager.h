#pragma once
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<numeric>
#include<functional>
#include<map>
#include<fstream>
#include"speaker.h"
using namespace std;

class SpeechManager
{
public:
	SpeechManager();

	//菜单功能
	void show_Menu();

	//开始比赛
	void startSpeech();
	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//3.显示晋级结果
	void showScore();
	//保存记录
	void saveRecore();
	//读取记录
	void loadRecord();
	//显示往届记录
	void showRecord();
	//判断文件是否为空
	bool fileIsEmpty;
	//存放往届记录
	map<int, vector<string>>m_Record;

	//清空功能
	void clearRecord();

	//退出功能
	void exitSystem();

	~SpeechManager();

	//初始化
	void initSpeech();

	//创建12名选手
	void createSpeaker();

	//成员属性
	//保存第一次比赛选手的编号
	vector<int>v1;

	//保存第二次选手的编号
	vector<int>v2;

	//胜出前三名选手的编号
	vector<int>vVictory;

	//存放编号以及对应的具体选手
	map<int, Speaker>m_Speaker;

	//比赛的次数
	int m_Index=0;
};
