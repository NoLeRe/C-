#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

namespace My_std{

	template<class T>
	struct list_node{
		T val;
		list_node<T>* prev;
		list_node<T>* next;
		list_node(const T& x = T())
			:val(x)
			, prev(nullptr)
			, next(nullptr)
		{}
	};
	template<class T,class ref ,class ptr>
	struct list_iterator{
		typedef list_node<T> Node;
		typedef list_iterator<T, ref, ptr> self;
		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{}
		ref operator* ()
		{
			return _node->val;
		}
		ptr operator->()
		{
			return &(_node->val);
		}
		bool operator!=(list_iterator<T>& it)
		{
			return _node != it._node;
		}
		bool operator==(list_iterator<T>& it)
		{
			return _node == it._node;
		}
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		self &operator--()
		{
			_node = _node->prev;
		}
		self operator++(int)
		{
			list_iterator<T> tmp(*this);
			_node = _node->next;
			return tmp;
		}
		self operator--(int)
		{
			list_iterator<T> tmp(*this);
			_node = _node->prev;
			return tmp;
		}

	};
	template<class T>
	class list{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		list()
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
		}
		list(cosnt list<T>& l1)
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;

			for (auto e : l1)
				push_back(e);
			return *this;
		}
		/*list operator=(const list<T>& l1)
		{
			if (this != &l1)
			{
				clear();
				for (auto e : l1)
					push_back(e);
			}
		}*/
		list operator=(list<T>& l1)
		{
			swap(_head, l1._head);
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		iterator begin()
		{
			return iterator(_head->next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		void push_back(const T& x)
		{
			Node* tail = _head->prev;
			Node* node = new Node(x);
			tail->next = node;
			node->prev = tail;
			node->next = _head;
			_head->prev = node;
		}
		void pop_back()
		{
			assert(_head->next != _head);
			Node* tail = _head->prev;
			Node* pre = tail->prev;
			pre->next = _head;
			_head->prev = pre;
			delete[] tail;
		}
		void push_front(const T& x)
		{
			Node* Next = _head->next;
			Node* node = new Node(x);
			_head->next = node;
			node->next = Next;
			Next->prev = node;
			node->prev = _head;
		}
		void pop_front()
		{
			assert(_head->next != _head);
			Node* Next = _head->next;
			_head->next = Next->next;
			Next->next->prev = _head;
			delete[] Next;
		}

		void insert(iterator pos, const T& x)
		{
			Node* node = new Node(x);
			Node* cur = pos._node;
			Node* pre = cur->prev;
			pre->next = node;
			node->next = cur;
			cur->prev = node;
			node->prev = pre;
		}
		iterator erase(iterator pos)
		{
			assert(pos._node->next != pos._node);
			Node* pre = pos._node->prev;
			Node* next = pos._node->next;
			pre->next = next;
			next->prev = pre;
			delete pos._node;
			return next;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
	private:
		Node* _head;
	};
	void test_1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.pop_back();
		l1.push_front(0);
		l1.pop_front();
		l1.insert(l1.begin(),0);
		l1.erase(l1.begin());
		l1.clear();
		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

}

