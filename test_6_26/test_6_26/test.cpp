bool canJump(vector<int>& nums) {
	int k = 0;

	for (int i = 0; i<nums.size(); i++)
	{
		if (k<i)
			return false;
		k = max(k, i + nums[i]);
	}
	return true;
}