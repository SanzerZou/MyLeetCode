#include "mainheader.h"

ListNode* reverseList(ListNode* head) {
	ListNode* cur = head;
	ListNode* end = NULL;
	while (cur != NULL){
		ListNode* tp = cur;
		cur = cur->next;
		tp->next = end;
		end = tp;
	}
	return end;
}