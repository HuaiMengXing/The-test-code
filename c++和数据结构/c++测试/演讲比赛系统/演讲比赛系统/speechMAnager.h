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

	//�˵�����
	void show_Menu();

	//��ʼ����
	void startSpeech();
	//��ǩ
	void speechDraw();
	//����
	void speechContest();
	//3.��ʾ�������
	void showScore();
	//�����¼
	void saveRecore();
	//��ȡ��¼
	void loadRecord();
	//��ʾ�����¼
	void showRecord();
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	//��������¼
	map<int, vector<string>>m_Record;

	//��չ���
	void clearRecord();

	//�˳�����
	void exitSystem();

	~SpeechManager();

	//��ʼ��
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//��Ա����
	//�����һ�α���ѡ�ֵı��
	vector<int>v1;

	//����ڶ���ѡ�ֵı��
	vector<int>v2;

	//ʤ��ǰ����ѡ�ֵı��
	vector<int>vVictory;

	//��ű���Լ���Ӧ�ľ���ѡ��
	map<int, Speaker>m_Speaker;

	//�����Ĵ���
	int m_Index=0;
};
