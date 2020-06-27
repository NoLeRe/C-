#include"FileManager.h"
#include"fileutil.h"

void FileManager::scannerDir(const std::string& path)
{
	_file.clear();
	searchDir(path, _file);
	std::cout << "all file: " << std::endl;
	showAllFile();
	getMd5toFile();
	showCopyList();
	getCopyList();
	std::cout << "show cpoylist: " << std::endl;
	showCopyList();
	showAllFile();

}
void FileManager::getMd5toFile()
{
	_md5toFile.clear();
	for (const auto& f : _file)
	{
		_md5toFile.insert(std::make_pair(_md5.GetfileMD5(f.c_str()), f));
	}
}
void FileManager::getCopyList()
{
	_filetoMd5.clear();
	auto it = _md5toFile.begin();
	while (it != _md5toFile.end())
	{
		if (_md5toFile.count(it->first) > 1)
		{
			auto pairit = _md5toFile.equal_range(it->first);
			auto begin = pairit.first;
			while (begin != pairit.second)
			{
				_filetoMd5.insert(std::make_pair(begin->second, begin->first));
				begin++;
			}
			it = pairit.second;
		}
		else
		{
			_file.erase(it->second);
			it = _md5toFile.erase(it);
		}
	}

}
void FileManager::showCopyList()
{
	auto it = _md5toFile.begin();
	int totalsize = _md5toFile.size();
	int count = 0;
	while (it != _md5toFile.end())
	{
		int idx = 1;
		auto pairti = _md5toFile.equal_range(it->first);
		auto curit = pairti.first;
		std::cout << "cur MD5: " << it->first << std::endl;
		while (curit != pairti.second)
		{
			std::cout << "\t第" << idx << "个文件：";
			std::cout << curit->second << std::endl;
			idx++;
			curit++;
			count++;
		}
		it = pairti.second;
	}
	std::cout << "文件总数： " << totalsize << std::endl;
}
void FileManager::showAllFile()
{
	for (const auto& e : _file)
	{
		std::cout << e << std::endl;
	}
	std::cout << "文件总数： " << _file.size() << std::endl;
}
void FileManager::deleteByName(const std::string& name)
{
	if (_filetoMd5.count(name) == 0)
	{
		std::cout << name << "No Exist!" << std::endl;
		return;
	}
	int count = 0;
	std::string curMd5 = _filetoMd5[name];
	std::cout << "File: " << name << "count--->" << _md5toFile.count(curMd5) << std::endl;
	auto pairit = _md5toFile.equal_range(curMd5);
	auto curit = pairit.first;
	while (curit != pairit.second)
	{
		if (curit->second != name)
		{
			_file.erase(curit->second);
			_filetoMd5(curit->second);
			deletFile(curit->second.c_str());
			count++;
		}
		curit++;
	}
	curit = pairit.first;
	while (curit != pairit.second)
	{
		if (curit->second != name)
		{
			_md5toFile.erase(curit);
			pairit = _md5toFile.equal_range(curMd5);
			curit = pairit.first;
		}
		curit++;
	}
	std::cout << "delete files: " << count << std::endl;
}
void FileManager::deleteByMd5(const std::string& md5)
{
	if (_md5toFile.count(md5) == 0)
	{
		std::cout << md5 << "No Exist!" << std::endl;
		return;
	}
	std::cout << md5 << "---->" << _md5toFile.count(md5) << std::endl;
	int count = 0;
	auto pairit = _md5toFile.equal_range(md5);
	auto curit = pairit.first;
	curit++;
	while (curit != pairit.second)
	{
		_file.erase(curit->second);
		_filetoMd5.erase(curit->second);
		deletFile(curit->second.c_str());
		curit++;
		count++;
	}
	curit = pairit.first;
	curit++;
	_md5toFile.erase(curit, pairit.second);
	std::cout << "delete file: " << count << std::endl;
}
void FileManager::deleteAllCopy()
{	
	std::unordered_set<std::string> md5set;
	for (const auto& e : _md5toFile)
	{
		md5set.insert(e.first);
	}
	for (const auto& e : md5set)
	{
		deleteByMd5(e);
	}
}
//模糊删除匹配所有包含"matchName"的文件的副本
void FileManager::deleteMatchName(const std::string& matchName)
{
	std::unordered_set<std::string> fileset;
	for (const auto& e : _file)
	{
		if (e.find(matchName)!=std::string::npos)
			fileset.insert(e);
	}
	for (const auto& f : fileset)
	{
		if (_filetoMd5.count(f) != 0)
		{
			deleteByName(f);
		}
	}
}