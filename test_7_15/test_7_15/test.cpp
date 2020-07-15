// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;
int dfs(vector<vector<char>>& v, int row, int col)
{
	if (row<0 || row >= v.size() || col<0 || col >= v[0].size())
		return 0;
	if (v[row][col] != '.')
		return 0;
	v[row][col] = '@';
	return 1 + dfs(v, row + 1, col) + dfs(v, row - 1, col) + dfs(v, row, col + 1) + dfs(v, row, col - 1);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int row, col;
		vector<vector<char>> v(m, vector<char>(n));
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					row = i;
					col = j;
					v[i][j] = '.';
				}
			}
		}
		int max = dfs(v, row, col);

		cout << max << endl;


	}
	return 0;
}