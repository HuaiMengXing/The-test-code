#include"speechMAnager.h"
#include"speaker.h"

int main()
{
	srand((unsigned int)time(NULL));

	//���������
	SpeechManager sm;
	int choice = 0;

	/*for (map<int,Speaker>::iterator i = sm.m_Speaker.begin(); i != sm.m_Speaker.end(); i++)
	{
		cout << "ѡ�ֱ�ţ�" << i->first << " " << "���֣�" << i->second.m_Name << " " << "������" << i->second.m_Score[1] << endl;
	}*/

	while (true)
	{
		sm.show_Menu();

		cout << "���������ѡ��" << endl;
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
			system("cls");//����
			break;
		}
	}


	system("pause");
	return 0;
}