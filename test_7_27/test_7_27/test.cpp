int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

	int totol = 0;
	int cur = 0;
	int ret = 0;

	for (int i = 0; i<gas.size(); i++)
	{
		totol += gas[i] - cost[i];
		cur += gas[i] - cost[i];
		if (cur<0)
		{
			cur = 0;
			ret = i + 1;
		}
	}
	return totol<0 ? -1 : ret;
}