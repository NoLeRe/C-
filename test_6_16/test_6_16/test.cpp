class Solution {
public:
	ListNode* reverseList(ListNode* head) {

		ListNode* cur = head;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;

		while (cur)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};