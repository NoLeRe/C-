#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	long long arr[90] = { 0 };
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i<90; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int n;
	while (cin >> n)
	{
		cout << arr[n - 1] << endl;
	}
	return 0;
}