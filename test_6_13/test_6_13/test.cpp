#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {

		ListNode* pre = head;
		ListNode* last = head;
		while (m - 1>0)
		{
			pre = pre->next;
			m--;
		}
		while (n - 1>0)
		{
			last = last->next;
			n--;
		}
		stack<int> st;
		ListNode* cur = pre;
		while (pre != last->next)
		{
			st.push(pre->val);
			pre = pre->next;
		}
		while (!st.empty())
		{
			cur->val = st.top();
			st.pop();
			cur = cur->next;
		}
		return head;

	}
};