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
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void print()
	{
		cout << _year << " 年 " << _month << " 月 " << _day << " 日" << endl;
	}
	int GetMonthDay(int year, int month)
	{
		int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
		{
			return 29;
		}
		return monthday[month];
	}
	bool operator>(Date& d)
	{
		return _year > d._year&&_month > d._month&&_day > d._day;
	}
	bool operator<(Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year&&_month < d._month)
			return true;
		else if (_year == d._year&&_month == d._month&&_day < d._day)
			return true;
		else
			return false;
	}
	bool operator==(Date& d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator!=(Date& d)
	{
		return !(*this == d);
	}
	Date operator+(int day)
	{
		if (day<0)
		{
			Date ret(*this);
			ret -= -day;
			return ret;
		}
		Date ret(*this);
		ret._day += day;
		while(ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._month = 1;
				ret._year++;
			}
		}
		return ret;
	}

	Date operator-(int day)
	{
		if (day < 0)
		{
			Date ret(*this);
			ret += -day;
			return ret;
		}
		Date ret(*this);
		ret._day -= day;
		while (ret._day < 0)
		{
			ret._month--;
			if (ret._month == 0)
			{
				ret._month = 12;
				ret._year--;
			}
			ret._day += GetMonthDay(ret._year, ret._month);
		}
		return ret;
	}
	Date& operator+=(int day)
	{
		*this = *this + day;
		return *this;
	}
	Date& operator-=(int day)
	{
		*this = *this - day;
		return *this;
	}
	Date& operator--()
	{
		return *this -= 1;
	}
	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	Date& operator++()
	{
		return *this += 1;
	}
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	int operator-(const Date& d)
	{
		Date max(*this);
		Date min(d);
		int flag = 1;
		int day = 0;
		if (max < min)
		{
			flag = -1;
			max=d;          //赋值重载，不是拷贝构造
			min=*this;		//赋值重载，不是拷贝构造
		}
		while (min != max)
		{
			min++;
			day++;
		}
		return day*flag;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 4, 16);
	Date d2(2020, 10, 1);
	//d2--;
	//d2.print();
	cout << d1 - d2 << endl;
	system("pause");
	return 0;
}