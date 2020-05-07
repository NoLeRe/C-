#include<iostream>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {


		int next = 0;
		int num1_end = num1.size() - 1;
		int num2_end = num2.size() - 1;
		string s;
		while (num1_end >= 0 || num2_end >= 0)
		{
			int x = 0, y = 0;
			if (num1_end >= 0)
			{
				x = num1[num1_end] - '0';
			}
			if (num2_end >= 0)
			{
				y = num2[num2_end] - '0';
			}
			int sum = x + y + next;
			next = sum / 10;
			sum %= 10;
			s += sum + '0';
			num1_end--;
			num2_end--;
		}
		if (next == 1)
		{
			s += '1';
		}
		reverse(s.begin(), s.end());
		return s;
	}
};