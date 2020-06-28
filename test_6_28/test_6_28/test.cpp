int maxProfit(vector<int>& prices) {
	int minprice = INT_MAX;
	int ret = 0;

	for (int i = 0; i<prices.size(); i++)
	{
		minprice = min(prices[i], minprice);
		ret = max(ret, prices[i] - minprice);
	}
	return ret;

}