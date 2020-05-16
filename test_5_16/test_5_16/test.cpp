#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {

		int val = 0;
		for (auto e : nums)
		{
			val ^= e;
		}

		int i;
		for (i = 0; i<32; i++)
		{
			if (val&(1 << i))
				break;
		}
		int num_1 = 0;
		int num_2 = 0;
		for (int j = 0; j<nums.size(); j++)
		{
			if (nums[j] & (1 << i))
				num_1 ^= nums[j];
			else
				num_2 ^= nums[j];
		}
		vector<int> v;
		v.push_back(num_1);
		v.push_back(num_2);
		return v;
	}
};