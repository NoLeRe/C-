class CQueue {
public:
	stack<int> st_1;
	stack<int> st_2;
	CQueue() {
		while (!st_1.empty())
			st_1.pop();
		while (!st_2.empty())
			st_2.pop();

	}

	void appendTail(int value) {
		st_1.push(value);
	}

	int deleteHead() {
		if (st_2.empty())
		{
			while (!st_1.empty())
			{
				st_2.push(st_1.top());
				st_1.pop();
			}
		}
		if (st_2.empty())
			return -1;
		int ret = st_2.top();
		st_2.pop();
		return ret;
	}
};

/**
* Your CQueue object will be instantiated and called as such:
* CQueue* obj = new CQueue();
* obj->appendTail(value);
* int param_2 = obj->deleteHead();
*/