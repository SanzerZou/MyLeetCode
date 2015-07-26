#include "mainheader.h"
/*
	深刻理解交换次数
*/
ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode root(0);
	root.next = head;
	n -= m;
	ListNode* pre = &root;
	while (--m)
		pre = pre->next;
	ListNode* pStart = pre->next;
	while (n--){
		ListNode* p = pStart->next;
		pStart->next = p->next;
		p->next = pre->next;
		pre->next = p;
	}
	return root.next;
}