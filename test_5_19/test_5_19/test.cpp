#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {

		vector<vector<int>> v;

		v.resize(numRows);

		for (int i = 0; i<numRows; i++)
		{
			v[i].resize(i + 1, 0);
			v[i][0] = 1;
			int sz = v[i].size();
			v[i][sz - 1] = 1;
			for (int j = 0; j<sz; j++)
			{
				if (v[i][j] != 1)
				{
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
				}
			}
		}
		return v;
	}
};