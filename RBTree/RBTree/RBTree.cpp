#include<iostream>
#include<time.h>
using namespace std;

enum color
{
	RED,BLACK
};
template<class K,class V>
struct RBNode{
	pair<K,V> _val;
	RBNode<K,V>* _parent;
	RBNode<K,V>* _left;
	RBNode<K,V>* _right;
	color _color;

	RBNode(const pair<K, V> val = pair<K, V>())
		:_val(val)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _color(RED)
	{}
};

template<class K,class V>
class RBTree{
public:
	typedef RBNode<K, V> Node;
	RBTree()
	{
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
		_header->_parent = nullptr;
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
	bool insert(const pair<K, V>& val)
	{
		if (_header->_parent == nullptr)
		{
			Node* root = new Node(val);
			root->_parent = _header;
			_header->_parent = root;
			_header->_left = root;
			_header->_right = root;
			root->_color = BLACK;
			return true;
		}
		Node* cur= _header->_parent;
		Node* pre = nullptr;
		while (cur)
		{
			if (cur->_val.first == val.first)
				return false;
			else if (cur->_val.first > val.first)
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
		if (cur->_val.first < pre->_val.first)
			pre->_left = cur;
		else
			pre->_right = cur;
		cur->_parent = pre;

		while (cur!=_header->_parent&&cur->_parent->_color==RED)
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
			return true;
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

void test()
{
	RBTree<int, int> tree;
	tree.insert(make_pair(5, 1));
	tree.insert(make_pair(50, 1));
	tree.insert(make_pair(-2, 1));
	tree.insert(make_pair(9, 1));
	tree.insert(make_pair(21, 1));
	cout<<tree.IsRbTree()<<endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}