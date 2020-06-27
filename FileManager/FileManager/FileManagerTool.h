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
		cout << "请输入需要扫描的文件夹:" << endl;
		std::string path;
		getline(cin, path);
		_fm.scannerDir(path);
	}
	void deletebyMd5()
	{
		cout << "请输入需要删除文件的Md5值:" << endl;
		std::string md5;
		cin >> md5;
		_fm.deleteByMd5(md5);
	}
	void deletebyName()
	{
		cout << "请输入需要删除的文件名：" << endl;
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
		cout << "请输入匹配文件名：" << endl;
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