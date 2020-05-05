int maxProfit(int* prices, int pricesSize){

	/*int max=0;
	for(int i=0;i<pricesSize-1;i++)
	{
	for(int j=i+1;j<pricesSize;j++)
	{
	if(prices[j]-prices[i]>max)
	max=prices[j]-prices[i];
	}
	}
	return max;*/
	int max = 0;
	int *dp = (int*)malloc(sizeof(int)*pricesSize);
	memset(dp, 0, pricesSize*sizeof(int));

	for (int i = 1; i<pricesSize; i++)
	{
		dp[i] = dp[i - 1] + prices[i] - prices[i - 1];
		if (dp[i] <= 0)
			dp[i] = 0;
		if (dp[i]>max)
			max = dp[i];
	}
	return max;

}