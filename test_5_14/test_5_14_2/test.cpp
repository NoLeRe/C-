#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {

	int bitpos[32] = { 0 };
	int sum = 0;
	for (int i = 0; i<32; i++)
	{
		for (auto e : nums)
		{
			if (e&(1 << i))
				bitpos[i]++;
		}
		bitpos[i] %= 3;
		sum += bitpos[i] << i;
	}
	return sum;
}

int main()
{
	int a[] = { -2, -2, 1, 1, -3, 1, -3, -3, -4, -2 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	cout << singleNumber(v) << endl;
	system("pause");
	return 0;
}