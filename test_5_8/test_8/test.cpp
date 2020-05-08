#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
	int nthUglyNumber(int n) {

		if (n<7)
			return n;
		vector<int> num(n);
		num[0] = 1;

		int index_1 = 0, index_2 = 0, index_3 = 0;

		for (int i = 1; i<n; i++)
		{
			num[i] = min(num[index_1] * 2, min(num[index_2] * 3, num[index_3] * 5));
			if (num[i] == num[index_1] * 2)
				index_1++;
			if (num[i] == num[index_2] * 3)
				index_2++;
			if (num[i] == num[index_3] * 5)
				index_3++;
		}
		return num[n - 1];

	}
};