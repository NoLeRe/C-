#include<iostream>
using namespace std;

template<class T>
struct Node{
	T _val;
	Node<T>* _left;
	Node<T>* _right;

	Node(const T val = T())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class T>
class BsTree{
public:
	typedef Node<T> Node;
	BsTree()
		:_root(nullptr)
	{}
	Node* find(const T& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_val == val)
				return cur;
			else if (val < cur->_val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return cur;
	}
	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* pre = nullptr;
		while (cur)
		{
			if (val == cur->_val)
				return false;
			else if (val < cur->_val)
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
		//cur = new Node(val);
		if (val<pre->_val)
			pre->_left = new Node(val);
		else
			pre->_right = new Node(val);
		return true;
	}
	bool erase(const T& val)
	{
		if (_root == nullptr)
			return false;
		Node* cur = _root;
		Node* pre = cur;
		while (cur)
		{
			if (cur->_val == val)
				break;
			else if (cur->_val < val)
			{
				pre = cur;
				cur = cur->_right;
			}
			else
			{
				pre = cur;
				cur = cur->_left;
			}
		}
		if (cur == nullptr)
			return false;
		if (cur->_right == nullptr)
		{
			if (cur != _root)
			{
				if (pre->_left == cur)
					pre->_left = cur->_left;
				else
					pre->_right = cur->_left;
			}
			else
				_root = cur->_left;
			delete cur;
			cur = nullptr;
		}
		else if (cur->_left == nullptr)
		{
			if (cur != _root)
			{
				if (pre->_left == cur)
					pre->_left = cur->_right;
				else
					pre->_right = cur->_right;
			}
			else
				_root = cur->_right;
			delete cur;
			cur = nullptr;
		}
		else
		{
			Node* parent = cur;
			Node* child = cur->_left;
			while (child->_right)
			{
				parent = child;
				child = child->_right;
			}
			cur->_val = child->_val;
			if (parent->_left == child)
				cur->_left = child->_left;
			else
				parent->_right = child->_left;
			delete child;
			child = nullptr;
		}
		return true;
	}
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_val << " ";
			_inorder(root->_right);
		}
	}
	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
private:
	Node* _root;
};

int main()
{
	BsTree<int> tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(1);
	tree.insert(4);
	tree.insert(0);
	tree.insert(2);
	tree.insert(7);
	tree.insert(6);
	tree.insert(8);
	tree.insert(9);

	tree.inorder();
	tree.erase(5);
	tree.inorder();
	tree.erase(0);
	tree.erase(3);
	tree.erase(7);
	tree.inorder();
	system("pause");
	return 0;
}