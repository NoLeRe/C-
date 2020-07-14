#include<iostream>
#include<string>
using namespace std;

int count(string s)
{
	int ret = 0;
	for (int i = 0; i<s.size(); i++)
	{
		ret = ret * 26 + s[i] - 'a';
	}
	return ret;
}
int main()
{
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		cout << (count(s2) - count(s1) - 1) % 1000007 << endl;
	}
	return 0;
}