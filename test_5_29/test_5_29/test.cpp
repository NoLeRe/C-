#include<iostream>
using namespace std;

int totalday[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int totalmoney[] = { 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };

bool isprime(int month)
{
	if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)
		return true;
	return false;
}
bool isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
int calday(int day1, int day2, int month)
{
	int sum = day2 - day1 + 1;
	if (!isprime(month))
		sum *= 2;
	return sum;
}

int calmonth(int month1, int month2, int year)
{
	int sum = 0;
	for (int i = month1; i <= month2; i++)
	{
		sum += totalmoney[i - 1];
		if (i == 2 && isleap(year))
			sum += 1;
	}
	return sum;
}

int calyear(int year1, int year2)
{
	int sum = 0;
	for (int i = year1; i <= year2; i++)
	{
		sum += calmonth(1, 12, i);
	}
	return sum;
}

int main()
{
	int year1, month1, day1;
	int year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int ret = 0;
		if (year1 == year2)
		{
			if (month1 == month2)
				ret += calday(day1, day2, month1);
			else
			{
				ret += calmonth(month1, month2, year1);
				ret -= calday(1, day1 - 1, month1);
				ret -= calday(day2 + 1, totalday[month2 - 1], month2);
			}
		}
		else
		{
			ret += calyear(year1 + 1, year2 - 1);
			ret += calmonth(month1 + 1, 12, year1);
			ret += calmonth(1, month2 - 1, year2);
			ret += calday(day1, totalday[month1 - 1], month1);
			ret += calday(1, day2, month2);
		}
		cout << ret << endl;
	}
	return 0;
}