#include<iostream>
using namespace std;

int getmonthday(int year, int month)
{
	int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;
	return a[month];
}

void print(int year, int day)
{
	int month = 1;
	while (day>getmonthday(year, month))
	{
		day -= getmonthday(year, month);
		month++;
		if (month == 13)
		{
			month = 1;
			year++;
		}
	}
	cout << year << "-";
	if (month<10)
		cout << 0 << month << "-";
	else
		cout << month << "-";
	if (day<10)
		cout << 0 << day << endl;
	else
		cout << day << endl;
}

int main()
{
	int year, day;
	cin >> year >> day;
	print(year, day);
	return 0;
}