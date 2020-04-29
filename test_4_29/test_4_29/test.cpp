#include<iostream>
using namespace std;


int compare(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}

int singleNumber(int* nums, int numsSize){
	qsort(nums, numsSize, sizeof(int), compare);
	if (numsSize == 1)
		return nums[0];
	if (nums[0] != nums[1])
		return nums[0];
	if (nums[numsSize - 1] != nums[numsSize - 2])
		return nums[numsSize - 1];
	for (int i = 3; i<numsSize - 3; i += 3)
	{
		if (nums[i] != nums[i + 1])
			return nums[i];
	}
	return -1;


}