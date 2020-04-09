#include<iostream>
using namespace std;

class Date{

public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator==(Date& d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator!=(Date& d)
	{
		return !(*this == d);
	}
	bool operator<(Date& d)
	{
		if (_year<d._year)
			return true;
		if (_year == d._year&&_month<d._month)
			return true;
		if (_year == d._year&&_month == d._month&&_day<d._day)
			return true;
		return false;
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
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	int operator-(Date& d)
	{
		Date max(*this);
		Date min(d);
		if (max<min)
		{
			max = d;
			min = *this;
		}
		int count = 1;
		while (min != max)
		{
			count++;
			++min;
		}
		return count;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int input1, input2;
	cin >> input1;
	cin >> input2;
	int year1 = input1 / 10000;
	int month1 = (input1 / 100) % 100;
	int day1 = input1 % 100;
	int year2 = input2 / 10000;
	int month2 = (input2 / 100) % 100;
	int day2 = input2 % 100;
	Date d1(year1, month1, day1);
	Date d2(year2, month2, day2);
	int num = d1 - d2;
	cout << num << endl;
	return 0;
}