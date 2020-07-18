pair<ListNode*, ListNode*> myreverse(ListNode* head, ListNode*tail)
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
	return{ tail, head };
}
ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* hair = new ListNode(0);
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
		auto cur = myreverse(head, tail);

		head = cur.first;
		tail = cur.second;
		pre->next = head;
		tail->next = next;
		pre = tail;
		head = pre->next;
	}
	return hair->next;
}