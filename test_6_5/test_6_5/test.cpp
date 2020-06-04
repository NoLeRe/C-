#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		vector<string> v;
		v.resize(n);
		for (int i = 0; i<n; i++)
		{
			getline(cin, v[i]);
		}
		for (int i = 0; i<n; i++)
		{
			if (v[i].find(",") != string::npos || v[i].find(" ") != string::npos)
			{
				v[i].insert(v[i].begin(), '"');
				v[i].insert(v[i].end(), '"');
			}

		}
		for (int i = 0; i<n - 1; i++)
		{
			cout << v[i] << ", ";
		}
		cout << v[v.size() - 1] << endl;
	}
	return 0;
}