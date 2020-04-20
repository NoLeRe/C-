#include<iostream>
using namespace std;

class sum{
public:
	sum()
	{
		count += i;
		i++;
	}
	static void init()
	{
		i = 1;
		count = 0;
	}
	static int getsum()
	{
		return count;
	}
private:
	static int i;
	static int count;
};
int sum::i = 1;
int sum::count = 0;

class Solution {
public:

	int Sum_Solution(int n) {
		sum::init();
		sum a[n];
		return sum::getsum();
	}

};