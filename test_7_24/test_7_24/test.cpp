vector<int> searchRange(vector<int>& nums, int target) {

	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		if (nums[left] == target)
		{
			while (nums[right] != target)
			{
				right--;
			}
			return{ left, right };
		}
		left++;
	}
	return{ -1, -1 };
}