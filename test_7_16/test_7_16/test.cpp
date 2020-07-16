#include<iostream>
using namespace std;

int Hoare(int* a, int begin, int end)
{
	int key = a[end];
	int index = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		while (begin < end&&a[begin] >= key)
			end--;
		swap(a[begin], a[end]);
		begin++;
		end--;
	}
	swap(a[begin], a[index]);
	return begin;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int index = Hoare(a, begin, end);
	QuickSort(a, begin, index - 1);
	QuickSort(a, index + 1, end);
}

//void merge(int* a, int begin, int end, int* tmp)
//{
//	if (begin >= end)
//		return;
//	int mid = (begin + end) / 2;
//	merge(a, begin, mid, tmp);
//	merge(a, mid + 1, end, tmp);
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int index = begin;
//	while (begin1 <= end1&&begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//			tmp[index++] = a[begin1++];
//		else
//			tmp[index++] = a[begin2++];
//	}
//	if (begin1 <= end1)
//	{
//		while (begin1 <= end1)
//			tmp[index++] = a[begin1++];
//	}
//	else
//	{
//		while (begin2 <= end2)
//			tmp[index++] = a[begin2++];
//	}
//	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
//}
//
//void MergeSort(int* a, int begin, int end)
//{
//	int* tmp = new int[sizeof(a) / sizeof(int)];
//	merge(a, begin, end, tmp);
//	delete[] tmp;
//}