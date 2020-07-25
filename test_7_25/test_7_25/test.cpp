vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> ret;
	if (nums.size()<3)
		return ret;

	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i]>0)
			break;
		if (i>0 && nums[i - 1] == nums[i])
			continue;
		int left = i + 1;
		int right = nums.size() - 1;
		while (left<right)
		{
			int num = nums[i] + nums[left] + nums[right];
			if (num == 0)
			{
				ret.push_back({ nums[i], nums[left], nums[right] });
				left++;
				right--;
				while (left<right&&nums[left] == nums[left - 1])
					left++;
				while (left<right&&nums[right] == nums[right + 1])
					right--;
			}
			if (num<0)
				left++;
			if (num>0)
				right--;
		}
	}
	return ret;
}