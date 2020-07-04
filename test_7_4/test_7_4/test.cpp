#include<iostream>
using namespace std;

//¶ÑÅÅĞò
void AdjustDown(int* a,int root, int n)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] < a[child])
			child++;
		if (a[parent]>a[child])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDown(a, i, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		AdjustDown(a, 0, i);
	}
}

//¹é²¢ÅÅĞò
void _mergesort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_mergesort(a, begin, mid, tmp);
	_mergesort(a, mid + 1, end, tmp);
	int begin1 = begin, begin2 = mid + 1;
	int end1 = mid, end2 = end;
	int index = begin;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
		{
			tmp[index++] = a[begin1++];
		}
	}
	else
	{
		while (begin2 <= end2)
		{
			tmp[index++] = a[begin2++];
		}
	}
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void MergeSort(int*a, int n)
{
	int* tmp = new int[n];
	_mergesort(a, 0, n - 1, tmp);
}

int main()
{
	int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	//HeapSort(a,10);
	MergeSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}