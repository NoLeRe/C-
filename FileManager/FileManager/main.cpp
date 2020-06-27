#include"FileManagerTool.h"
#include<iostream>

void menu()
{
	cout << "************************************" << endl;
	cout << "***********文件管理工具*************" << endl;
	cout << "1.扫描文件           2.删除文件(Md5)" << endl;
	cout << "3.删除文件(name)     4.删除所有副本 " << endl;
	cout << "5.展示所有副本       6.展示所有文件 " << endl;
	cout << "7.模糊匹配删除       0.退出         " << endl;
	cout << "************************************" << endl;
}

int main()
{
	int input;
	FileManagerTool fm;
	do{
		menu();
		std::string garbage;
		cin >> input;
		getline(cin, garbage);
		switch (input)
		{
		case 1:
			fm.scanner();
			break;
		case 2:
			fm.deletebyMd5();
			break;
		case 3:
			fm.deletebyName();
			break;
		case 4:
			fm.deleteAllCopy();
			break;
		case 5:
			fm.ShowCopy();
			break;
		case 6:
			fm.ShowAllfile();
			break;
		case 7:
			fm.deleteFuzzyMatchFile();
			break;
		default:
			break;
		}

	} while (input != 0);

	return 0;
}