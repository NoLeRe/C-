#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string s1;
	while (getline(cin, s1))
	{
		string s2;
		getline(cin, s2);
		vector<string> v;
		for (int i = 0; i<s1.size(); i++)
		{
			if (s1[i] == '"')
			{
				v.push_back(s1.substr(i + 1, s1.find('"', i + 1) - i - 1));
				i = s1.find('"', i + 1) + 1;
			}
			else
			{
				if (s1.find(',', i) == string::npos)
				{
					v.push_back(s1.substr(i));
					i = s1.size();
				}
				else
				{
					v.push_back(s1.substr(i, s1.find(',', i) - i));
					i = s1.find(',', i);
				}
			}
		}
		if (find(v.begin(), v.end(), s2) == v.end())
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
	}
	return 0;
}