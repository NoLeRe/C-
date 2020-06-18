#include<iostream>
#include<vector>
using namespace std;

enum state{
	EXIST,
	DELETE,
	EMPTY
};
template<class K,class V>
struct Node{

	pair<K, V> _val;
	state _state;
};

template<class K,class V>
class HashTable{
public:
	HashTable(int N = 10)
	{
		_table.resize(N);
		_size = 0;
		for (size_t i = 0; i < N; i++)
		{
			_table[i]._state = EMPTY;
		}
	}
	bool inser(const pair<K, V>& val)
	{
		Checkcapcity();
		int index = val.first%_table.size();
		while (_table[index]._state == EXIST)
		{
			if (_table[index]._val.first == val.first)
				return false;
			index++;
			if (index == _table.size())
				index = 0;
		}
		_table[index]._val = val;
		_table[index]._state = EXIST;
		_size++;
		return true;
	}
	bool erase(const K& key)
	{
		int index = key%_table.size();
		while (_table[index]._state == EXIST)
		{
			if (_table[index]._val.first == key)
			{
				_table[index]._state = DELETE;
				return true;
			}
			index++;
		}
		return false;
	}
	void Checkcapcity()
	{
		if (_size * 10 / _table.size() >= 7)
		{
			int newcapcity = _table.size() * 2;
			HashTable<K, V> _newtable(newcapcity);
			for (int i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state==EXIST)
					_newtable.inser(_table[i]._val);
			}
			_table.swap(_newtable._table);
		}
	}
	void print()
	{
		for (int i = 0; i < _table.size(); i++)
		{
			if (_table[i]._state == EXIST)
				cout << _table[i]._val.first << "->" << _table[i]._val.first << "\t";
		}
		cout << endl;
	}
private:
	vector<Node<K, V>> _table;
	size_t _size;
};

void test()
{
	HashTable<int, int> hash;
	hash.inser(make_pair(3,1));
	hash.inser(make_pair(7, 1));
	hash.inser(make_pair(43, 1));
	hash.inser(make_pair(35, 1));
	hash.inser(make_pair(8, 1));
	hash.inser(make_pair(12, 1));
	hash.print();
	cout<<hash.erase(7)<<endl;
	hash.print();
	cout<<hash.erase(1)<<endl;
	hash.print();
	
}
template<class K,class V>
struct Node{
	V _val;
	Node<K, V>* next;

	Node(const V& val = V())
		:_val(val)
		, next(nullptr)
	{}
};


template<class K>
struct HashFun
{
	int operator()(const K& key)
	{
		return key;
	}
};
template<>
struct HashFun<string>
{
	int operator()(const string& key)
	{
		int hash = 0;
		for (const auto& ch : key)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

template<class K, class V, class Keyofval,class Hashfun>
class Hash_Bucket;

template<class K,class V,class Keyofval,class Hashfun=HashFun<K>>
struct Hash_iterator{
	typedef Node<K, V> Node;
	typedef Hash_Bucket<K, V, Keyofval,Hashfun> hash;
	typedef Hash_iterator<K, V,Keyofval,Hashfun> self;
	Node* _node;
	hash* _ht;
	Hash_iterator(Node* node,hash* ht)
		:_node(node)
		, _ht(ht)
	{}
	V& operator*()
	{
		return _node->_val;
	}
	V* operator->()
	{
		return &_node->_val;
	}
	bool operator!=(self& it)
	{
		return _node != it._node;
	}
	self& operator++()
	{
		if (_node->next)
			_node = _node->next;
		else
		{
			Keyofval kov;
			Hashfun hf;
			int index = hf(kov(_node->_val)) % _ht->_bucket.size();
			index++;
			for (; index < _ht->_bucket.size(); index++)
			{
				if (_ht->_bucket[index])
				{
					_node = _ht->_bucket[index];
					break;
				}
			}
			if (index == _ht->_bucket.size())
				_node = nullptr;
		}
		return *this;
	}
};


template<class K,class V,class Keyofval,class Hashfun>
class Hash_Bucket{
public:
	typedef Node<K, V> Node;
	typedef Hash_iterator<K, V, Keyofval,Hashfun> iterator;
	friend Hash_iterator<K, V,Keyofval,Hashfun>;
	Hash_Bucket(size_t N = 10)
	{
		_bucket.resize(N,nullptr);
		_size = 0;
	}
	iterator begin()
	{
		for (int i = 0; i < _bucket.size(); i++)
		{
			if (_bucket[i])
				return iterator(_bucket[i],this);
		}
		return end();
	}
	iterator end()
	{
		return iterator(nullptr,this);
	}
	pair<iterator,bool> insert(const V& val)
	{
		Checkcpacity();

		Keyofval kov;
		Hashfun hf;
		int index = hf(kov(val)) % _bucket.size();
		Node* cur = _bucket[index];
		while (cur)
		{
			if (hf(kov(cur->_val)) == hf(kov(val)))
				return make_pair(iterator(cur,this),false);
			cur = cur->next;
		}
		cur = new Node(val);
		cur->next = _bucket[index];
		_bucket[index] = cur;
		_size++;
		return make_pair(iterator(cur,this),true);
	}
	void Checkcpacity()
	{
		if (_size == _bucket.size())
		{
			int newcapcity = _bucket.size() == 0 ? 10 : 2 * _bucket.size();
			vector<Node*> new_bucket;
			new_bucket.resize(newcapcity);
			Keyofval kov;
			Hashfun hf;
			for (int i = 0; i < _bucket.size(); i++)
			{
				Node* cur = _bucket[i];
				while (cur)
				{
					Node* next = cur->next;
					int index = hf(kov(cur->_val)) % newcapcity;
					cur->next = new_bucket[index];
					new_bucket[index] = cur;
					cur = next;
				}
				_bucket[i] = nullptr;
			}
			_bucket.swap(new_bucket);
		}
	}
	Node* Find(const V& val)
	{
		Keyofval kov;
		Hashfun hf;
		int index = hf(kov(val)) % _bucket.size();
		Node* cur = _bucket[index];
		while (cur)
		{
			if (hf(kov(cur->_val)) == hf(kov(val)))
				return cur;
			cur = cur->next;
		}
		return nullptr;
	}
	
	size_t Size()const
	{
		return _size;
	}
	bool Empty()const
	{
		for (int i = 0; i < _bucket.size(); i++)
		{
			if (_bucket[i])
				return false;
		}
		return true;
	}
	void Clear()
	{
		for (int i = 0; i < _bucket.size(); i++)
		{
			_bucket[i] = nullptr;
		}
	}
	bool BucketCount()const
	{
		int count = 0;
		for (int i = 0; i < _bucket.size(); i++)
		{
			if (_bucket[i])
				count++;
		}
		return count;
	}
	void Swap(Hash_Bucket<K, V,Keyofval,Hashfun>& ht)
	{
		_bucket.swap(ht._bucket);
		swap(_size, ht._size);
	}
	~Hash_Bucket()
	{
		_size = 0;
	}
	/*void print()
	{
		Keyofval kov;
		for (int i = 0; i < _bucket.size(); i++)
		{
			Node* cur = _bucket[i];
			while (cur)
			{
				cout << kov(cur->_val) << " ";
				cur = cur->next;
			}
			cout << endl;
		}
	}*/
private:
	vector<Node*> _bucket;
	size_t _size;
};
//template<class K,class V>
//struct Keyofval{
//	const V& operator()(const V& val)
//	{
//		return val;
//	}
//};

template<class K, class V,class Hashfun=HashFun<K>>
class my_unordermap{
	struct mapofval{
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename Hash_Bucket<K, pair<K, V>, mapofval,Hashfun>::iterator iterator;
	iterator begin()
	{
		return _hash.begin();
	}
	iterator end()
	{
		return _hash.end();
	}
	pair<iterator, bool> insert(pair<K, V>& val)
	{
		return _hash.insert(val);
	}
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _hash.insert(make_pair(key,V()));
		return (*(ret.first)).second;
	}
private:
	Hash_Bucket<K, pair<K, V>, mapofval ,Hashfun> _hash;
};


template<class K,class Hashfun=HashFun<K>>
class my_unorderset{
	struct setofval{
		const K& operator()(const K& val)
		{
			return val;
		}
	};
public:
	typedef typename Hash_Bucket<K, K,setofval,Hashfun>::iterator iterator;
	iterator begin()
	{
		return _hash.begin();
	}
	iterator end()
	{
		return _hash.end();
	}
	pair<iterator, bool> insert(const K& val)
	{
		return _hash.insert(val);
	}
private:
	Hash_Bucket<K, K, setofval, Hashfun> _hash;
};
//void test_2()
//{
//	Hash_Bucket<int, int, Keyofval<int,int>> HB;
//	HB.insert(25);
//	HB.insert(56);
//	HB.insert(4);
//	HB.insert(14);
//	HB.insert(45);
//	HB.insert(34);
//	HB.insert(41);
//	HB.insert(17);
//	HB.insert(11);
//	HB.print();
//}

//void test_3()
//{
//	Hash_Bucket<int, int, Keyofval<int, int>> hb;
//	hb.insert(25);
//	hb.insert(56);
//	hb.insert(4);
//	hb.insert(14);
//	hb.insert(45);
//	hb.insert(34);
//	hb.insert(41);
//	hb.insert(17);
//	hb.insert(11);
//	
//	Hash_Bucket<int, int, Keyofval<int, int>> ::iterator it = hb.begin();
//	while (it != hb.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
void test_4()
{
	my_unordermap<int, int> mp;
	mp.insert(make_pair(25, 1));
	mp.insert(make_pair(56, 2));
	mp.insert(make_pair(4,  3));
	mp.insert(make_pair(14, 4));
	mp.insert(make_pair(45, 5));
	mp.insert(make_pair(34, 6));
	mp.insert(make_pair(41, 7));
	mp.insert(make_pair(17, 8));
	mp.insert(make_pair(11, 9));
	mp[34] = 10;
	mp[100] = 0;
	my_unordermap<int, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << "-->" << it->second << " ";
		++it;
	}
	cout << endl;
}
void test_5()
{
	my_unorderset<int> set;
	set.insert(25);
	set.insert(56);
	set.insert(4);
	set.insert(14);
	set.insert(45);
	set.insert(34);
	set.insert(41);
	set.insert(17);
	set.insert(11);
	my_unorderset<int>::iterator it = set.begin();
	while (it != set.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	//test();
	//test_2();
	//test_3();
	test_4();
	//test_5();
	system("pause");
	return 0;
}