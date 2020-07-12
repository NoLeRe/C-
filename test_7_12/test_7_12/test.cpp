
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v(n);
		vector<bool> ret(n, true);
		for (auto& e : v)
			cin >> e;
		sort(v.begin(), v.end());
		//[](string a,string b){return a.size()<b.size();}
		for (int i = 0; i<n - 1; i++)
		{
			if (v[i] == v[i + 1])
				ret[i] = false;
			else if (v[i].size() < v[i + 1].size() && v[i] == v[i + 1].substr(0, v[i].size()) && v[i + 1][v[i].size()] == '/')
				ret[i] = false;
		}

		for (int i = 0; i<ret.size(); i++)
		{
			if (ret[i])
				cout << "mkdir -p" << " " << v[i] << endl;
		}
		cout << endl;
	}
	return 0;
}