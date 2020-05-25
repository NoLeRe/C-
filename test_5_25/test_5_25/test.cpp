#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
class Solution {
public:

	vector<string> topKFrequent(vector<string>& words, int k) {

		map<string, int> mp;
		for (auto& e : words)
			mp[e]++;

		vector<pair<string, int>> v;
		vector<string> ret;

		for (auto e : mp)
			v.push_back(e);

		sort(v.begin(), v.end(), [](const pair<string, int>& left, const pair<string, int>& right) {
			if (left.second == right.second)
				return left.first<right.first;
			return left.second>right.second; });
			for (int i = 0; i<k; i++)
				ret.push_back(v[i].first);

			return ret;
	}
};