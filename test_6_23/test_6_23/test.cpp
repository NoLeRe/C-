class Solution {
public:
	int maxArea(vector<int>& height) {

		int begin = 0;
		int end = height.size() - 1;

		int maxret = 0;
		while (begin<end)
		{
			int tmp = min(height[begin], height[end])*(end - begin);
			maxret = max(maxret, tmp);
			if (height[begin]<height[end])
				begin++;
			else
				end--;
		}
		return maxret;
	}
};