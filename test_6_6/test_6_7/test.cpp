#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		set<int> s;
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
			s.insert(v[i]);
		}
		auto it = s.begin();
		int k;
		cin >> k;
		for (int i = 0; i<k - 1; i++)
			it++;
		cout << *it << endl;
	}
	return 0;
}