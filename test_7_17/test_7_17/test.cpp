string removeKdigits(string num, int k) {

	int len = num.size();
	int sz = len - k;
	string ret;
	if (sz == 0)
		return "0";

	for (int i = 0; i<len; i++)
	{
		while (k&&ret.size() && ret.back()>num[i])
		{
			ret.pop_back();
			k--;
		}
		ret += num[i];
	}
	ret.resize(sz);
	while (!ret.empty() && ret[0] == '0')
		ret.erase(ret.begin());
	if (!ret.empty())
		return ret;
	else
		return "0";
}