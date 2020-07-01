int cuttingRope(int n) {
	if (n<4)
		return n - 1;

	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++)
	{
		for (int j = 1; j <= i / 2; j++)
		{
			dp[i] = max(dp[i], dp[i - j] * dp[j]);
		}
	}
	return dp[n];
}