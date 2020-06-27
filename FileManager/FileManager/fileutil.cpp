#include"fileutil.h"

void searchDir(const std::string& path, std::unordered_set<std::string>& subFiles)
{
	std::string matchfile = path + "\\" + "*.*";
	_finddata_t fileAttr;
	long handle = _findfirst(matchfile.c_str(), &fileAttr);
	if (handle == -1)
	{
		perror("search failed");
		std::cout << matchfile;
		return;
	}
	do
	{
		if (fileAttr.attrib & _A_SUBDIR)
		{
			if (strcmp(fileAttr.name, ".") != 0 && strcmp(fileAttr.name, "..") != 0)
				searchDir(path + "\\" + fileAttr.name, subFiles);
		}
		else
			subFiles.insert(path + "\\" + fileAttr.name);
	} while (_findnext(handle, &fileAttr) == 0);
	_findclose(handle);
}
void deletFile(const char* filename)
{
	if (remove(filename) == 0)
	{
		std::cout << "delete file:" << filename << "success!" << std::endl;
	}
	else
	{
		perror("delete file failed");
	}
}