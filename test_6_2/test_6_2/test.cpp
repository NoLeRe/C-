#include<iostream>
using namespace std;

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
				a[end + 1] = a[end];
			else
				break;
			end--;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
					a[end + gap] = a[end];
				else
					break;
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

void SelectSort(int *a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i]>a[maxi])
				maxi = i;
		}
		swap(a[begin], a[mini]);
		if (maxi == begin)
			maxi = mini;
		swap(a[end], a[maxi]);
		begin++;
		end--;
	}
}
void AdjustDown(int* a, int root, int n)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		AdjustDown(a, 0, i);
	}
}
int Hoare(int* a, int begin, int end)
{
	int key = a[end];
	int index = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		while (begin<end&&a[end]>=key)
			end--;
		swap(a[begin], a[end]);
	}
	swap(a[index], a[begin]);
	return begin;
}
int Pit(int* a, int begin, int end)
{
	int pit = end;
	int key = a[pit];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		a[pit] = a[begin];
		pit = begin;
		while (begin < end&&a[end] >= key)
			end--;
		a[pit] = a[end];
		pit = end;
	}
	a[pit] = key;
	return pit;
}
int PreCur(int* a, int begin, int end)
{
	int cur = begin;
	int pre = begin - 1;
	while (cur < end)
	{
		if (a[cur] < a[end] && ++pre != cur)
			swap(a[cur], a[pre]);
		cur++;
	}
	pre++;
	swap(a[cur], a[pre]);
	return pre;
}

void QuickSort(int* a, int begin,int end)
{
	if (begin >= end)
		return;
	//int keyindex = Hoare(a, begin, end);
	//int keyindex = Pit(a, begin, end);
	int keyindex = PreCur(a, begin, end);
	QuickSort(a, begin, keyindex-1);
	QuickSort(a, keyindex + 1, end);

}
void _mergesort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_mergesort(a, begin, mid, tmp);
	_mergesort(a, mid + 1, end, tmp);
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
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
			tmp[index++] = a[begin1++];
	}
	else
	{
		while (begin2 <= end2)
			tmp[index++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = new int[n];
	_mergesort(a, 0, n - 1, tmp);
}

int main()
{
	int a[10] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	//InsertSort(a, 10);
	//ShellSort(a, 10);
	//SelectSort(a, 10);
	//HeapSort(a, 10);
	//QuickSort(a, 0, 9);
	MergeSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}