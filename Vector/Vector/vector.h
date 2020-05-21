#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace My_std{
	template<class T>

	class vector{
	public:
		typedef T* iterator;
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		/*vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			_finish = _start;
			_endofstorage = _start + v.capacity();
			for (size_t i = 0; i < v.size(); i++)
			{
				*_finish = v[i];
				_finish++;
			}
		}*/
		vector(const vector<int>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}
		~vector()
		{
			delete[] _start;
			_start=_finish = _endofstorage = nullptr;
		}
		vector<T>& operator=(const vector<T> v)
		{
			if (this != &v)
			{
				delete[] _start;
				_start = new T[v.capacity()];
				for (size_t i = 0; i < v.size(); i++)
				{
					_start[i] = v[i];
				}
				_finish = _start + v.size();
				_endofstorage = _start + v.capacity();
			}
			return *this;
		}
		/*vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}*/
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}
		iterator begin() const
		{
			return _start;
		}
		iterator end() const
		{
			return _finish;
		}
		void reserve(size_t n)
		{
			if (n>capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endofstorage = tmp + n;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n>capacity())
					reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}
		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 5 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;*/
			insert(_finish, x);
		}
		void pop_back()
		{
			_finish--;
		}
		void insert(iterator pos, const T& x)
		{
			assert(pos >= begin() && pos <= end());
			if (_finish == _endofstorage)
			{
				size_t sz = pos - _start;
				size_t newcapacity = capacity() == 0 ? 5 : 2 * capacity();
				reserve(newcapacity);
				pos = _start + sz;
			}
			iterator cur = _finish;
			while (cur!=pos)
			{
				*cur = *(cur - 1);
				cur--;
			}
			*pos = x;
			_finish++;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start&&pos < _finish);
			iterator cur = pos;
			while (cur < _finish-1)
			{
				*cur = *(cur + 1);
				cur++;
			}
			_finish--;
			return pos;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	
	void test_1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		//v.pop_back();
		v.push_back(4);
		v.push_back(5);
		v.insert(v.begin(), 0);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	void test_2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
				it = v.erase(it);
			else
				it++;
		}
		it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	void test_3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		vector<int> v2=v1;
		v2.resize(8);
		vector<int>::iterator it1 = v1.begin();
		vector<int>::iterator it2 = v2.begin();
		while (it1 != v1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		cout << endl;
		while (it2 != v2.end())
		{
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;
	}
};