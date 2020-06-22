class Solution {
public:
	pair<ListNode*, ListNode*> myreserve(ListNode* head, ListNode* tail)
	{
		ListNode* pre = tail->next;
		ListNode* cur = head;
		while (pre != tail)
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		return pair{ tail, head };
	}
	ListNode* reverseKGroup(ListNode* head, int k) {

		ListNode* hair = new ListNode;
		hair->next = head;
		ListNode* pre = hair;
		while (head)
		{
			ListNode* tail = pre;
			for (int i = 0; i<k; i++)
			{
				tail = tail->next;
				if (!tail)
					return hair->next;
			}
			ListNode* next = tail->next;
			pair<ListNode*, ListNode*> node = myreserve(head, tail);

			head = node.first;
			tail = node.second;
			pre->next = head;
			tail->next = next;
			pre = tail;
			head = tail->next;

		}
		return hair->next;
	}
};