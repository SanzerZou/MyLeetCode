#include "mainheader.h"

ListNode* insertionSortList(ListNode* head) {
	if (!head || !head->next)
		return head;
	ListNode root(INT_MIN);
	ListNode* cur = head->next;
	while (cur){
		ListNode* tp = &root;
		while (tp->val < cur->val && tp->next
			&& tp->next->val < cur->val){
			tp = tp->next;
		}
		ListNode* tp2 = cur;
		cur = cur->next;
		cur->next = tp2->next;
		tp->next = tp2;
	}
}