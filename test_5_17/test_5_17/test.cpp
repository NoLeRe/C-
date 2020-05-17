#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int sz = nums.size();
		if (sz == 0 || sz == 1)
			return sz;

		vector<int>::iterator it = nums.begin() + 1;
		int count = 1;
		while (it != nums.end())
		{
			if (*it == *(it - 1))
			{
				it = nums.erase(it);
			}
			else
			{
				count++;
				it++;
			}
		}
		return count;
	}
};