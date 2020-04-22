#include<iostream>
using namespace std;

class Date{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year=0, int month=0, int day=0)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void func()
	{
		_year = 1;
		_day = 1;
		_month = 1;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year <<" "<<d._month<<" "<<d._day<< endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year>>d._month>>d._day;
	return in;
}
int main()
{
	Date d(2020,4,22);
	cin >> d;
	cout << d << endl;
	d.func();
	cout << d << endl;
	system("pause");
	return 0;
}