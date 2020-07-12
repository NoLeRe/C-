string reverseWords(string s) {
	reverse(s.begin(), s.end());
	int begin = 0;
	int idx = 0;

	for (; begin<s.size(); begin++)
	{
		if (s[begin] != ' ')
		{
			if (idx != 0)
				s[idx++] = ' ';

			int end = begin;
			while (end<s.size() && s[end] != ' ')
				s[idx++] = s[end++];

			int len = end - begin;
			reverse(s.begin() + idx - len, s.begin() + idx);
			begin = end;
		}
	}
	s.erase(s.begin() + idx, s.end());
	return s;
}