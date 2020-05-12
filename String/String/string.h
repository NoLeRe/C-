#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

#pragma warning(disable:4996)
namespace my_std{

	class string{
	public:
		typedef char* iterator;
		friend istream& operator>>(istream& in, string& s);

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		string(char *str = "")  //构造函数
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(string& s)		//拷贝构造
		{
			if (this != &s)
			{
				_size = s._size;
				_capacity = s._capacity;
				_str = new char[_capacity + 1];
				strcpy(_str, s._str);
			}
		}
		//拷贝构造现代写法
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}
		/*string& operator=(const string& s)	//赋值重载
		{
			if (this != &s)
			{
				_size = s._size;
				_capacity = s._capacity;
				char* tmp = new char[_capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}*/
		//赋值重载现代写法
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}*/
		~string()				//析构函数
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		size_t size() const			//返回长度
		{
			return _size;
		}
		size_t capacity() const		//返回容量
		{
			return _capacity;
		}
		char& operator[](size_t i)	//[]运算符重载
		{
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}
		const char* c_str()        //c_str
		{
			return _str;
		}
		void reserve(size_t n)
		{
			if (n>_capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
				_str[_capacity] = '\0';

			}
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n<_size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				int i = _size;
				if (n > _capacity)
				{
					reserve(n);
				}
				_size = n;
				for (i; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 5 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void append(const char* s)
		{
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, s);
			_size += len;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(char* s)
		{
			append(s);
			return *this;
		}
		size_t find(char ch, size_t pos = 0)
		{
			for (int i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t find(char* s, size_t pos = 0)
		{
			char *p = strstr(_str, s);
			if (p == nullptr)
				return npos;
			else
				return p - _str;

		}
		string& insert(size_t pos, char ch)
		{
			assert(pos >= 0 && pos<_size);
			if (_size + 1>_capacity)
				reserve(_capacity + 1);
			for (int i = _size - 1; i > pos; i--)
			{
				_str[i] = _str[i - 1];
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		string& insert(size_t pos, char* s)
		{
			assert(pos >= 0 && pos<_size);
			int len = strlen(s);
			if (_size + len>_capacity)
				reserve(_capacity + len);
			int j = _size - 1;
			for (int i = _size + len - 1; i > _size - 1+pos; i--)
			{
				_str[i] = _str[j];
				j--;
			}
			int k = 0;
			for (int i = pos; i < _size+pos; i++)
			{
				_str[i] = s[k];
				k++;
			}
			_size += len;
			_str[_size] = '\0';
			return *this;
		}
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos||len>(_size-pos))
			{
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				int j = pos ;
				for (int i = pos + len ; i < _size; i++)
				{
					_str[j] = _str[i];
					j++;
				}
				_size -= len;
				_str[_size] = '\0';
			}
			return *this;

		}
		bool operator<(const string& s)
		{
			if (strcmp(_str, s._str)<0)
				return true;
			else
				return false;
		}
		bool operator==(const string& s)
		{
			if (strcmp(_str, s._str) == 0)
				return true;
			else
				return false;
		}
		bool operator<=(const string& s)
		{
			return *this<s || *this == s;
		}
		bool operator>(const string& s)
		{
			if (strcmp(_str, s._str) > 0)
				return true;
			else
				return false;
		}
		bool operator>=(const string& s)
		{
			return *this > s || *this == s;
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}


	private:
		char *_str;
		int _size;
		int _capacity;

		static size_t npos;
	};
	size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)  //cout重载
	{
		for (int i = 0; i < s.size(); i++)
		{
			cout << s[i];
		}
		return out;

	}
	istream& operator>>(istream& in, string& s)			//cin重载
	{
		while (1)
		{
			char ch;
			ch = in.get();
			if (ch == ' ' || ch == '\n')
				break;
			else
				s += ch;
		}
		return in;
	}
	void string_test_1()
	{
		string s1("hello");
		string s2(s1);
		string s3(" world");
		s1 = s3;
		string s4;
		cin >> s4;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s4 << endl;
	}
	void string_test_2()
	{
		string s1("hello");
		/*s1.reserve(30);
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;*/
		s1.resize(10, 'j');
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
		s1.push_back('a');
		cout << s1 << endl;
		s1.append("bcd");
		cout << s1 << endl;
		s1 += 'e';
		cout << s1 << endl;
		s1 += "fgh";
		cout << s1 << endl;
	}
	void string_test_3()
	{
		string s1("1234");
		s1.insert(3, '5');
		cout << s1 << endl;
		string s2("489");
		s2.insert(1, "567");
		cout << s2 << endl;
	}
	void string_test_4()
	{
		string s1("abc");
		string s2("def");
		if (s1 != s2)
			cout << "false" << endl;
		else
			cout << "true" << endl;
	}
	void string_test_5()
	{
		string s1("123456789");
		s1.erase(0, 9);
		cout << s1 << endl;
	}
	void string_test_6()
	{
		string s1("hello");
		string s2 = s1;
		cout << s1 << endl;
		cout << s2 << endl;
	}
	

};