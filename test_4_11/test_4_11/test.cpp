#include<iostream>
using namespace std;

class Date{
public:
	Date(int year = 0, int month = 0, int day = 0)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	int getmonthday(int year, int month)
	{
		int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return a[month];
	}
	Date& operator+=(int day)
	{
		_day += day;
		while (_day>getmonthday(_year, _month))
		{
			_day -= getmonthday(_year, _month);
			_month++;
			if (_month>12)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}
	void print()
	{
		cout << _year << "-";
		if (_month<10)
			cout << 0 << _month << "-";
		else
			cout << _month << "-";
		if (_day<10)
			cout << 0 << _day << endl;
		else
			cout << _day << endl;

	}
private:
	int _year;
	int _month;
	int _day;

};
int main()
{
	int m;
	cin >> m;
	for (int i = 0; i<m; i++)
	{
		int year, month, day, add;
		cin >> year >> month >> day >> add;
		Date d(year, month, day);
		d += add;
		d.print();
	}
	return 0;
}