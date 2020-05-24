#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string minNumber(vector<int>& nums) {


		vector<string> str;
		int len = nums.size();
		for (int i = 0; i<len; i++)
		{
			str.push_back(to_string(nums[i]));
		}
		sort(str.begin(), str.end(), [](string a, string b){return a + b<b + a; });
		string ret;
		for (auto e : str)
		{
			ret += e;
		}
		return ret;
	}
};