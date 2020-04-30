#include<iostream>
#include<string>
using namespace std;

void test_string_1()        //string类构造函数
{
	string s1("hello");
	string s2(s1);
	string s3(10, 'a');
	string s4;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}
void test_string_2()       //对string类的容量操作
{
	string s1("hello");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	if (!s1.empty())
	{
		cout << "true" << endl;
	}
	cout << s1.capacity() << endl;
	s1.reserve(5);
	cout << s1.capacity() << endl;
	s1.resize(20,'a');
	cout << s1 << endl;
	cout << s1.capacity() << endl;
}

void test_string_3()  //遍历操作，迭代器
{
	string s1("hello");
	string::iterator it = s1.begin();

	while (it != s1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;

	string::reverse_iterator rit= s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit;
		rit++;
	}
	cout << endl;

	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}
	cout << endl;
}

void test_string_4()  //对string类对象进行修改
{
	string s1("hello");
	s1.push_back('!');
	s1.append(" world");

	s1 += '!';
	s1 += "k";
	s1.insert(2, "a");
	string s2;
	cin >> s2;
	cout << s2 << endl;
}
void test_string_5()
{
	string s1("http://www.cplusplus.com/reference/string/string/npos/");
	size_t pos1 = s1.find(':');
	for (int i = 0; i < pos1; i++)
	{
		cout << s1[i];
	}
	cout << endl;
	size_t pos2 = s1.find("/", pos1 + 3);
	for (int i = pos1 + 3; i < pos2; i++)
	{
		cout << s1[i];
	}
	cout << endl;
	size_t pos3 = s1.find("/", pos2 + 1);
	for (int i = pos2 + 1; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cout << endl;
}



int main()
{
	//test_string_1();
	//test_string_2();
	//test_string_3();
	//test_string_4();
	test_string_5();
	system("pause");
	return 0;
}