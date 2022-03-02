#include"WorkerManager.h"
#include"Worker.h"
#include"personnel.h"
int main()
{
	WorkerManager use;
	char a='0';
	do
	{
		use.Show_Menu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ:";
		cin >> a;
		switch (a)
		{
		case '1':
			use.Add_emp();
			break;
		case '2':
			use.show();
			break;
		case '3':
			use.Del_emp();
			break;
		case '4':
			
			break;
		case '5':
			use.Mod_emp();
			break;
		case '6':break;
		case '7':break;
		case '8':
			use.clean_file();
			break;
		case '9':
			use.ExitSystem();
			break;
		default:
			break;
		}
	} while (true);
	
	system("pause");
	return 0;
}