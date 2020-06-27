#include"MD5.h"
#include"fileutil.h"
#include"FileManager.h"
using std::cout;
using std::endl;
void test()
{
	md5 md;
	uint32 n = 0x23456789;
	cout << md.ChangeHex(n) << endl;
}
void test2()
{
	md5 md;
	std::string s = "123456789abcdefgh";
	cout << md.GetstringMD5(s) << endl;
}
void test3()
{
	md5 md;
	const char* filepath = "md5.txt";
	const char* filepath2 = "md52.txt";
	cout << md.GetfileMD5(filepath) << endl;
	cout << md.GetstringMD5(filepath2) << endl;
}
//void test4()
//{
//	std::string s;
//	std::getline(std::cin, s);
//	std::vector<std::string> subfile;
//	searchDir(s, subfile);
//	for (auto &e : subfile)
//	{
//		cout << e << endl;
//	}
//}
void test5()
{
	FileManager fm;
	std::string path = ".";
	fm.scannerDir(path);
}

//int main()
//{
//	//test();
//	//test2();
//	//test3();
//	//test4();
//	test5();
//	system("pause");
//	return 0;
//}