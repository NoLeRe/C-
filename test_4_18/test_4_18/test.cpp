#include<stdio.h>
#include<stdlib.h>

bool isStraight(int* nums, int numsSize){

	int st[14] = { 0 };
	int joker = 0;
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == 0)
		{
			joker++;
			continue;
		}
		st[nums[i]]++;
		if (st[nums[i]]>1)
			return false;
		if (nums[i]<min)
			min = nums[i];
		if (nums[i]>max)
			max = nums[i];
	}
	//int card=max-min;
	if (max - min>4)
		return false;
	else
		return true;



}