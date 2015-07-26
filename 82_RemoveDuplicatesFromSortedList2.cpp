#include "mainheader.h"

ListNode* deleteDuplicates(ListNode* head) {
	ListNode root(0);
	root.next = head;
	ListNode* cur = &root;
	ListNode* nxt;
	while (cur != NULL && cur->next != NULL && cur->next->next != NULL){
		if (cur->next->val == cur->next->next->val)	{
			nxt = cur->next->next;
			while (nxt->next != NULL && nxt->next->val == cur->next->val)
				nxt = nxt->next;
			cur->next = nxt->next;
			cur = cur->next;
		}
	}
	return root.next;
	
}