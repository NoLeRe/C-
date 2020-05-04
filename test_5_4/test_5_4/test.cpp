#include<iostream>
#include<string>
using namespace std;

int isone(string s)
{
	int st[26] = { 0 };

	for (int i = 0; i<s.size(); i++)
	{
		st[s[i] - 'a']++;
	}
	for (int i = 0; i<s.size(); i++)
	{
		if (st[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	string s;
	cin >> s;
	int n = isone(s);
	if (n<0)
		cout << n << endl;
	else
		cout << s[n] << endl;
	system("pause");
	return 0;

}