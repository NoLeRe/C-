#pragma once
#include"MD5.h"
#include<string>
#include<unordered_set>
#include<unordered_map>
class FileManager{
public:
	void scannerDir(const std::string& path);
	void getMd5toFile();
	void getCopyList();
	void showCopyList();
	void showAllFile();

	void deleteByName(const std::string& name);
	void deleteByMd5(const std::string& md5);
	void deleteAllCopy();
	//ģ��ɾ��ƥ�����а���"matchName"���ļ��ĸ���
	void deleteMatchName(const std::string& matchName);
private:
	std::unordered_set<std::string> _file;
	std::unordered_map<std::string, std::string> _filetoMd5;
	std::unordered_multimap<std::string, std::string> _md5toFile;
	md5 _md5;
};