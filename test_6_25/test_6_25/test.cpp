class Solution {
public:
	int climbStairs(int n) {

		int pre = 0;
		int cur = 1;
		int ret;
		for (int i = 0; i<n; i++)
		{
			ret = pre + cur;
			pre = cur;
			cur = ret;
		}
		return ret;
	}
};