#include<iostream>
using namespace std;


int outDay(int year, int month, int day)
{
	int coutday = 0;
	int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		a[2] = 29;
	for (int i = 1; i<month; i++)
	{
		coutday += a[i];
	}
	coutday += day;
	return coutday;
}
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int num = outDay(year, month, day);
		cout << num << endl;
	}
	return 0;
}