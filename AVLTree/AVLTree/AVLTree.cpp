#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
struct AVLNode{
	AVLNode<T>* _parent;
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	T _val;
	int _bf;

	AVLNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _bf(0)
	{}
};

template<class T>
class AVLTree{
public:
	typedef AVLNode<T> Node;
	AVLTree() :_root(nullptr){}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent; //1
		parent->_left = subLR; //2
		if (subLR)
			subLR->_parent = parent; //3
		if (parent != _root)
		{
			Node* gparent = parent->_parent;
			if (gparent->_left == parent)
				gparent->_left = subL;   //4
			else
				gparent->_right = subL;
			subL->_parent = gparent;  //5
		}
		else
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		parent->_parent = subL; //6
		parent->_bf = subL->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subrL = subR->_left;

		subR->_left = parent;
		parent->_right = subrL;
		if (subrL)
			subrL->_parent = parent;
		if (parent != _root)
		{
			Node* gparent = parent->_parent;
			if (gparent->_left == parent)
				gparent->_left = subR;
			else
				gparent->_right = subR;
			subR->_parent = gparent;
		}
		else
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		parent->_parent = subR;
		parent->_bf = subR->_bf = 0;
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
			
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
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
		if (val < pre->_val)
		{
			pre->_left = cur;
			cur->_parent = pre;
		}
		else
		{
			pre->_right = cur;
			cur->_parent = pre;
		}
		//更新平衡因子，调整平衡度
		while (pre)
		{
			if (cur == pre->_left)
				--(pre->_bf);
			else
				++(pre->_bf);
			if (pre->_bf == 0)
				break;
			else if (abs(pre->_bf) == 1)
			{
				cur = pre;
				pre = pre->_parent;
			}
			else if (abs(pre->_bf) == 2)
			{
				if (pre->_bf == 2 && cur->_bf == 1)
					RotateL(pre);
				else if (pre->_bf == -2 && cur->_bf == -1)
					RotateR(pre);
				else if (pre->_bf == 2 && cur->_bf == -1)
				{
					Node* subR = pre->_right;
					Node* subrL = subR->_left;
					int bf = subrL->_bf;
					RotateR(cur);
					RotateL(pre);
					if (bf == 1)
					{
						subR->_bf = 0;
						pre->_bf = -1;
					}
					else if (bf == -1)
					{
						subR->_bf = 1;
						pre->_bf = 0;
					}

				}
				else if (pre->_bf==-2&&cur->_bf==1)
				{
					Node* subL = pre->_left;
					Node* sublR = subL->_right;
					int bf = sublR->_bf;
					RotateL(cur);
					RotateR(pre);
					if (bf == 1)
					{
						subL->_bf = -1;
						pre->_bf = 0;
					}
					else if (bf == -1)
					{
						subL->_bf = 0;
						pre->_bf = 1;
					}
				}
				break;
			}
			else
				assert(false);
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
	void Inorder()
	{
		_inorder(_root);
		cout << endl;
	}
	int length(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = length(root->_left)+1;
		int right = length(root->_right)+1;

		return left > right ? left : right;
	}
	bool _isavltree(Node* root)
	{
		if (root == nullptr)
			return true;
		int left = length(root->_left);
		int right = length(root->_right);
		if (right - left != root->_bf)
		{
			cout << "结点：" << root->_val << "平衡因子异常" << endl;
			return false;
		}
		return (abs(root->_bf) < 2) && _isavltree(root->_left) && _isavltree(root->_right);
	}
	bool IsAVLTree()
	{
		return _isavltree(_root);
	}
private:
	Node* _root;
};

void test()
{
	AVLTree<int> Tree;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		Tree.insert(a[i]);
	}
	Tree.Inorder();
	cout << Tree.IsAVLTree() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}