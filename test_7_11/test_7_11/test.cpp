#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class LRU{
public:
	void set(int key, int val)
	{
		_mp.insert(make_pair(key, val));
		_q.push(key);
		if (_mp.size()>3)
		{
			_mp.erase(_q.front());
			_q.pop();
		}
	}
	int get(int key)
	{
		if (_mp.find(key) == _mp.end())
			return -1;
		_q.pop();
		_q.push(key);
		return _mp.find(key)->second;
	}
private:
	unordered_map<int, int> _mp;
	queue<int> _q;
};
int main()
{
	int m, n;
	LRU lru;
	while (cin >> m >> n)
	{
		int option;
		while (cin >> option)
		{
			if (option == 1)
			{
				int key, val;
				cin >> key >> val;
				lru.set(key, val);
			}
			if (option == 2)
			{
				int key;
				cin >> key;
				cout << lru.get(key) << endl;
			}
		}
	}
	return 0;
}