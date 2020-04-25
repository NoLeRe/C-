#include<stdio.h>
#include<stdlib.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* singleNumbers(int* nums, int numsSize, int* returnSize){

	int *arr = (int*)malloc(sizeof(int)* 10001);
	int st[10001] = { 0 };
	int flag = 0;
	for (int i = 0; i<numsSize; i++)
	{
		st[nums[i]]++;
	}
	for (int i = 0; i<10001; i++)
	{
		if (st[i] == 1)
			arr[flag++] = i;
	}
	*returnSize = flag;
	return arr;

}