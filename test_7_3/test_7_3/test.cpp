int longestConsecutive(vector<int>& nums) {
	unordered_set<int> hash(nums.begin(), nums.end());
	int ret = 0;

	for (int i = 0; i<nums.size(); i++)
	{
		if (!hash.count(nums[i] - 1))
		{
			int curnum = nums[i];
			int curlong = 1;
			while (hash.count(curnum + 1))
			{
				curlong++;
				curnum++;
			}
			ret = max(ret, curlong);
		}
	}
	return ret;
}