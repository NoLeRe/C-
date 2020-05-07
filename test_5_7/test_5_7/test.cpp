#include<iostream>
using namespace std;

class Solution {
public:
	bool ischarornum(char c)
	{
		if ((c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9'))
			return true;
		else
			return false;
	}
	bool isPalindrome(string s) {

		for (auto& ch : s)
		{
			if (ch >= 'A'&&ch <= 'Z')
				ch += 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin<end)
		{
			while (begin<end&&!ischarornum(s[begin]))
				begin++;
			while (begin<end&&!ischarornum(s[end]))
				end--;
			if (s[begin] != s[end])
				return false;
			begin++;
			end--;
		}
		return true;
	}
};