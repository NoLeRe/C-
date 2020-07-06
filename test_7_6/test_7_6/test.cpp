#include<iostream>
using namespace std;


//快速排序
int Hoare(int* a, int begin, int end)
{
	int key = a[end];
	int index = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		while (begin < end&&a[end] >= key)
			end--;
		swap(a[begin], a[end]);
	}
	swap(a[begin], a[index]);
	return begin;
}
int Pit(int* a, int begin, int end)
{
	int key = a[end];
	int pit = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		swap(a[begin], a[pit]);
		pit = begin;
		while (begin < end&&a[end] >= key)
			end--;
		swap(a[end], a[pit]);
		pit = end;
	}
	a[pit] = key;
	return pit;
}
int PrevCur(int* a, int begin, int end)
{
	int cur = begin;
	int pre = cur - 1;
	while (cur < end)
	{
		if (a[cur] < a[end] && ++pre != cur)
		{
			swap(a[pre], a[cur]);
		}
		cur++;
	}
	pre++;
	swap(a[pre], a[cur]);
	return pre;

}

void QuickSort(int *a, int begin, int end)
{
	if (begin >= end)
		return;
	//int keyindex = Hoare(a, begin, end); //Hoare法
	//int keyindex = Pit(a, begin, end);   //挖坑法
	int keyindex = PrevCur(a, begin, end); //前后指针法
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);

}



int main()
{
	int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	QuickSort(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}