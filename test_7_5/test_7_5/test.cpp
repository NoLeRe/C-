#include<iostream>
using namespace std;

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
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
//œ£∂˚≈≈–Ú
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

void SelectSort(int* a, int n)
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
		if (begin == maxi)
			maxi = mini;
		swap(a[end], a[maxi]);
		begin++;
		end--;
	}
}


int main()
{
	int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	//InsertSort(a, 10);
	//ShellSort(a, 10);
	SelectSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}