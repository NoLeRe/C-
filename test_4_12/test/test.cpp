#include<iostream>
using namespace std;

class Data{
public:
	Data(int year = 0, int month = 0,int day = 0)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	int GetMonthDay(int year, int month)
	{
		static int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
		{
			return 29;
		}
		return monthday[month];
	}
	void printf()
	{
		cout << _year << "Äê" << _month << "ÔÂ" << _day << "ÈÕ" << endl;
	}
	bool operator==(const Data& d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator>(const Data& d)
	{
		if (_year > d._year)
			return true;
		if (_year == d._year&&_month > d._month)
			return true;
		if (_year == d._year&&_month == d._month&&_day > d._day)
			return true;
		return false;
	}
	bool operator<(const Data& d)
	{
		return !operator>(d);
	}
	bool operator>=(const Data& d)
	{ 
		return operator>(d) || operator==(d);
	}
	bool operator<=(const Data& d)
	{
		return operator<(d) || operator==(d);
	}
	bool operator!=(const Data& d)
	{
		return !operator==(d);
	}
	Data operator+(int day)
	{
		Data ret(*this);
		ret._day += day;
		while(ret._day>GetMonthDay(ret._year, ret._month))
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
	Data operator-(int day)
	{
		Data ret(*this);
		ret._day -= day;
		while (ret._day < 0)
		{
			ret._day += GetMonthDay(ret._year, ret._month);
			ret._month--;
			if (ret._month == 0)
			{
				ret._month = 12;
				ret._year--;
			}
		}
		return ret;
	}
	Data& operator+=(int day)
	{
		/*_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}*/
		*this = *this + day;
		return *this;
	}
	Data& operator-=(int day)
	{
		/*_day -= day;
		while (_day < 0)
		{
			_day += GetMonthDay(_year, _month);
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
		}*/
		*this = *this - day;
		return *this;
	}
	Data& operator++()
	{
		*this += 1;
		return *this;
	}
	Data& operator--()
	{
		*this -= 1;
		return *this;
	}


private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//Data d1;
	Data d2(2020,4,13);
	Data d3(d2);
	d3 += 200;
	d3 -= 200;
	d3.printf();
	system("pause");
	return 0;

}