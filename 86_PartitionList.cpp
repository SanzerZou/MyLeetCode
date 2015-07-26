#include "mainheader.h"

ListNode* partition(ListNode* head, int x) {
	ListNode root1(0);
	ListNode* cur1 = &root1;
	ListNode root2(0);
	ListNode* cur2 = &root2;
	while (head != NULL){
		if (head->val < x){
			cur2->next = head;
			cur2 = cur2->next;
			head = head->next;
		}
		else{
			cur1->next = head;
			cur1 = cur1->next;
			head = head->next;
		}
	}
	cur2->next = root1.next;
	cur1->next = NULL;
	return root2.next;
}