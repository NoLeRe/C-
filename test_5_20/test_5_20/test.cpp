#include<iostream>
using namespace std;
class Solution {
public:

	string reverseWords(string s) {
		auto it = s.begin();
		auto cur = it;

		while (cur<s.end())
		{
			while (*cur != ' '&&cur<s.end())
				cur++;
			reverse(it, cur);
			while (*cur == ' '&&cur<s.end())
				cur++;
			it = cur;
		}
		reverse(it, s.end());
		return s;

	}
};