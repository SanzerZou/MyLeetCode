#include "mainheader.h"

ListNode* removeElements(ListNode* head, int val) {
	ListNode root(0);
	root.next = head;
	ListNode* cur = &root;
	while (cur->next){
		if (cur->next->val == val)
			cur->next = cur->next->next;
		else
			cur = cur->next;
	}
	return root.next;
}