#include"speechMAnager.h"
#include"speaker.h"

int main()
{
	srand((unsigned int)time(NULL));

	//管理类对象
	SpeechManager sm;
	int choice = 0;

	/*for (map<int,Speaker>::iterator i = sm.m_Speaker.begin(); i != sm.m_Speaker.end(); i++)
	{
		cout << "选手编号：" << i->first << " " << "名字：" << i->second.m_Name << " " << "分数：" << i->second.m_Score[1] << endl;
	}*/

	while (true)
	{
		sm.show_Menu();

		cout << "请输入你的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		case 0:
			sm.exitSystem();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}


	system("pause");
	return 0;
}