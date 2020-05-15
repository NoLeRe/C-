#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
	map<char, string> M = {
		{ '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" },
		{ '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" },
	};

	vector<string> ret;
	string cur;
	void DFS(int index, string& digits)
	{
		if (index == digits.size())
		{
			ret.push_back(cur);
			return;
		}

		for (int i = 0; i<M[digits[index]].size(); i++)
		{
			cur.push_back(M[digits[index]][i]);
			DFS(index + 1, digits);
			cur.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {

		if (digits.size() == 0)
			return ret;
		DFS(0, digits);
		return ret;
	}
};