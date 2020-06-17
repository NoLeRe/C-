class Solution {
public:
	ListNode* swapPairs(ListNode* head) {

		ListNode* newhead = new ListNode;
		newhead->next = head;

		ListNode* pos = newhead;
		while (head&&head->next)
		{
			ListNode* first = head;
			ListNode* second = head->next;

			pos->next = second;
			first->next = second->next;
			second->next = first;

			pos = first;
			head = first->next;
		}
		return newhead->next;

	}
};