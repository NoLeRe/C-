#include"FileManagerTool.h"
#include<iostream>

void menu()
{
	cout << "************************************" << endl;
	cout << "***********�ļ�������*************" << endl;
	cout << "1.ɨ���ļ�           2.ɾ���ļ�(Md5)" << endl;
	cout << "3.ɾ���ļ�(name)     4.ɾ�����и��� " << endl;
	cout << "5.չʾ���и���       6.չʾ�����ļ� " << endl;
	cout << "7.ģ��ƥ��ɾ��       0.�˳�         " << endl;
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