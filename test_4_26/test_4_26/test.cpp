#include<iostream>
using namespace std;

class Solution {
public:
	Solution()
	{
		sum += count;
		count++;
	}
	void init()
	{
		count = 1;
		sum = 0;
	}
	int sumNums(int n) {
		init();
		Solution *a=new Solution[n];
		return sum;
	}
private:
	static int count;
	static int sum;
};
int Solution::count = 1;
int Solution::sum = 0;