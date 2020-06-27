#pragma once
#include<iostream>
#include"FileManager.h"

using std::cin;
using std::cout;
using std::endl;

class FileManagerTool{
public:
	void scanner()
	{
		cout << "��������Ҫɨ����ļ���:" << endl;
		std::string path;
		getline(cin, path);
		_fm.scannerDir(path);
	}
	void deletebyMd5()
	{
		cout << "��������Ҫɾ���ļ���Md5ֵ:" << endl;
		std::string md5;
		cin >> md5;
		_fm.deleteByMd5(md5);
	}
	void deletebyName()
	{
		cout << "��������Ҫɾ�����ļ�����" << endl;
		std::string name;
		getline(cin, name);
		_fm.deleteByName(name);
	}
	void deleteAllCopy()
	{
		_fm.deleteAllCopy();
	}
	void deleteFuzzyMatchFile()
	{
		cout << "������ƥ���ļ�����" << endl;
		std::string name;
		getline(cin, name);
		_fm.deleteMatchName(name);
	}
	void ShowCopy()
	{
		_fm.showCopyList();
	}
	void ShowAllfile()
	{
		_fm.showAllFile();
	}
private:
	FileManager _fm;
};