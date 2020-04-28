#include<stdio.h>
#include<stdlib.h>

int maxnum(int *a, int left, int right)
{
	int max = INT_MIN;
	for (int i = left; i <= right; i++)
	{
		if (a[i]>max)
			max = a[i];
	}
	return max;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
	if (numsSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}

	int size = (numsSize - k) + 1;
	int* arr = (int*)malloc(sizeof(int)*size);

	int left = 0, right = k - 1;
	int i = 0;
	while (right<numsSize)
	{
		arr[i] = maxnum(nums, left, right);
		i++;
		left++;
		right++;
	}
	*returnSize = size;
	return arr;
}