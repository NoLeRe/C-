// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
		dp[0][0] = (s1[0] == s2[0]) ? 1 : 0;
		for (int i = 1; i<s1.size(); i++)
		{
			dp[i][0] = (s1[i] == s2[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int i = 1; i<s2.size(); i++)
		{
			dp[0][i] = (s2[i] == s1[0]) ? 1 : 0;
			dp[0][i] = max(dp[0][i - 1], dp[0][i]);
		}
		for (int i = 1; i<s1.size(); i++)
		{
			for (int j = 1; j<s2.size(); j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (s1[i] == s2[j])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[s1.size() - 1][s2.size() - 1] << endl;
	}
	return 0;
}