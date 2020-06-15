#include<iostream>
using namespace std;

	enum color
	{
		RED, BLACK
	};
	template<class V>
	struct RBNode{
		V _val;
		RBNode<V>* _parent;
		RBNode<V>* _left;
		RBNode<V>* _right;
		color _color;

		RBNode(const V val = V())
			:_val(val)
			, _parent(nullptr)
			, _left(nullptr)
			, _right(nullptr)
			, _color(RED)
		{}
	};
	template<class V>
	struct RBiterator
	{
		typedef RBNode<V> Node;
		typedef RBiterator<V> self;
		Node* _node;
		RBiterator(Node* node)
			:_node(node)
		{}
		V& operator*()
		{
			return _node->_val;
		}
		V* operator->()
		{
			return &_node->_val;
		}
		bool operator!=(const self& it)
		{
			return _node!=it._node;
		}
		self& operator++()
		{
			if (_node->_right)
			{
				_node = _node->_right;
				while (_node->_left)
					_node = _node->_left;
			}
			else
			{
				Node* pre = _node->_parent;
				while (pre->_right == _node)
				{
					_node = pre;
					pre = pre->_parent;
				}
				if (_node->_right != pre)
					_node = pre;
			}
			return *this;
		}
		self& operator--()
		{
			if (_node->_left)
			{
				_node = _node->_left;
				while (_node->_right)
					_node = _node->_right;
			}
			else
			{
				Node* pre = _node->_parent;
				while (_node == pre->_left)
				{
					_node = pre;
					pre = pre->_parent;
				}
				if (_node->_left != pre)
					_node = pre;
			}
			return *this;
		}

	};

	template<class K, class V,class keyofval>
	class RBTree{
	public:
		typedef RBNode<V> Node;
		typedef RBiterator<V> iterator;
		RBTree()
		{
			_header = new Node();
			_header->_left = _header;
			_header->_right = _header;
			_header->_parent = nullptr;
		}
		iterator begin()
		{
			return iterator(_header->_left);
		}
		iterator end()
		{
			return iterator(_header);
		}
		iterator rbegin()
		{
			return iterator(_header->_right);
		}
		iterator rend()
		{
			return iterator(_header);
		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* sublR = subL->_right;

			subL->_right = parent;
			parent->_left = sublR;
			if (sublR)
				sublR->_parent = parent;
			if (parent != _header->_parent)
			{
				Node* gparent = parent->_parent;
				if (parent == gparent->_left)
					gparent->_left = subL;
				else
					gparent->_right = subL;
				subL->_parent = gparent;
			}
			else
			{
				_header->_parent = subL;
				subL->_parent = _header;
			}
			parent->_parent = subL;
		}
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subrL = subR->_left;

			subR->_left = parent;
			parent->_right = subrL;
			if (subrL)
				subrL->_parent = parent;
			if (parent != _header->_parent)
			{
				Node* gparent = parent->_parent;
				if (parent == gparent->_left)
					gparent->_left = subR;
				else
					gparent->_right = subR;
				subR->_parent = gparent;
			}
			else
			{
				_header->_parent = subR;
				subR->_parent = _header;
			}
			parent->_parent = subR;
		}
		Node* leftto(Node* parent)
		{
			Node* cur = parent;
			while (cur&&cur->_left)
			{
				cur = cur->_left;
			}
			return cur;
		}
		Node* rightto(Node* parent)
		{
			Node* cur = parent;
			while (cur&&cur->_right)
			{
				cur = cur->_right;
			}
			return cur;
		}
		pair<iterator,bool> insert(const V& val)
		{
			if (_header->_parent == nullptr)
			{
				Node* root = new Node(val);
				root->_parent = _header;
				_header->_parent = root;
				_header->_left = root;
				_header->_right = root;
				root->_color = BLACK;
				return make_pair(iterator(root), true);
			}
			Node* cur = _header->_parent;
			Node* pre = nullptr;
			keyofval kov;
			while (cur)
			{
				if (kov(cur->_val) == kov(val))
					return make_pair(iterator(cur), false);
				else if (kov(cur->_val) > kov(val))
				{
					pre = cur;
					cur = cur->_left;
				}
				else
				{
					pre = cur;
					cur = cur->_right;
				}
			}
			cur = new Node(val);
			Node* newnode = cur;
			if (kov(cur->_val) < kov(pre->_val))
				pre->_left = cur;
			else
				pre->_right = cur;
			cur->_parent = pre;

			while (cur != _header->_parent&&cur->_parent->_color == RED)
			{
				Node* parent = cur->_parent;
				Node* gparent = parent->_parent;
				if (parent == gparent->_left)
				{
					Node* uncle = gparent->_right;
					if (uncle&&uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						gparent->_color = RED;
						cur = parent;
					}
					else
					{
						if (cur = parent->_right)
						{
							RotateL(parent);
							swap(parent, cur);
						}
						RotateR(gparent);
						parent->_color = BLACK;
						gparent->_color = RED;
						break;
					}

				}
				else
				{
					Node* uncle = gparent->_left;
					if (uncle&&uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						gparent->_color = RED;
						cur = parent;
					}
					else
					{
						if (cur == parent->_left)
						{
							RotateR(parent);
							swap(parent, cur);
						}
						RotateL(gparent);
						parent->_color = BLACK;
						gparent->_color = RED;
						break;
					}
				}
				_header->_parent->_color = BLACK;
				_header->_left = leftto(_header->_parent);
				_header->_right = rightto(_header->_parent);
				return make_pair(iterator(newnode), true);
			}
		}
		bool IsRbTree()
		{
			if (_header->_parent = _header)
				return true;
			Node* cur = _header->_parent;
			int blackcount = 0;
			while (cur)
			{
				if (cur->_color == BLACK)
					blackcount++;
				cur = cur->_left;
			}
			int k = 0;
			return _isrbtree(_header->_parent, k, blackcount);
		}
		bool _isrbtree(Node* root, int curblackcount, int totleblackcount)
		{
			if (root == nullptr)
			{
				if (curblackcount != totleblackcount)
				{
					cout << "每条路径黑色结点个数不同" << endl;
					return false;
				}
				else
					return true;
			}
			if (root->_color == BLACK)
				curblackcount++;
			Node* pre = root->_parent;
			if (pre->_color == RED&&root->_color == RED)
			{
				cout << "有连续红色结点" << endl;
				return false;
			}
			return _isrbtree(root->_left, curblackcount, totleblackcount)
				&& _isrbtree(root->_right, curblackcount, totleblackcount);
		}
	private:
		Node* _header;
	};

	template<class K,class V>
	class my_map{
		struct mapofval{
			const K& operator()(const pair<K,V>& val)
			{
				return val.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, mapofval>::iterator iterator;
		pair<iterator,bool> insert(const pair<K, V>& val)
		{
			return _rb.insert(val);
		}
		V& operator[](const K& key)
		{
			return (*(_rb.insert(make_pair(key, V())).first)).second;
		}
		iterator begin()
		{
			return _rb.begin();
		}
		iterator end()
		{
			return _rb.end();
		}
	private:
		RBTree<K, pair<K, V>, mapofval> _rb;
	};

	template<class V>
	class my_set{
		struct setofval{
			const V& operator()(const V& val)
			{
				return val;
			}
		};
		public:
			typedef typename RBTree<V, V, setofval>::iteraotr iterator;
			pair<iterator, bool> insert(const V& val)
			{
				return _rb.insert(val);
			}
			iterator begin()
			{
				return _rb.begin();
			}
			iterator end()
			{
				return _rb.end();
			}
		private:
			RBTree<V, V, setofval> _rb;
		};
	
	


int main()
{
	my_map<int, int> mp;
	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(2, 1));
	//mp.insert(make_pair(3, 1));
	//mp.insert(make_pair(4, 1));
	my_map<int, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << "->" << it->second << endl;
		++it;
	}
	system("pause");
	return 0;
}