#include<iostream>
#include<vector>
using namespace std;

namespace my_std{
	template<class T>
	struct less{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	template<class T>
	struct greater{
		bool operator()(const T& a, const T& b)
		{
			return a>b;
		}
	};

	template<class T, class container = vector<T>, class compare = less<T>>
	class priority_queue{
	public:
		void Adjustup(int root)
		{
			int child = root;
			int parent = (child - 1) / 2;
			compare com;
			while (child)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void Adjustdown(int root)
		{
			int parent = root;
			int child = parent * 2 + 1;
			compare com;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
					child++;
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			Adjustup(_con.size() - 1);
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjustdown(0);
		}
		T& top()
		{
			return _con[0];
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		container _con;
	};
	void test_1()
	{
		priority_queue<int> q;
		q.push(3);
		q.push(1);
		q.push(9);
		q.push(4);
		q.push(2);

		while (!q.empty())
		{
			cout << q.top() << " ";
			q.pop();
		}
		cout << endl;
	}
}