#include "mainheader.h"

ListNode* reverseKGroup(ListNode* head, int k) {
	if (!head || k == 1 || !head->next)
		return head;
	ListNode root(0);
	root.next = head;
	ListNode* newHead = &root;
	while (newHead){
		int j = k;
		ListNode* pro = newHead;
		ListNode* tp;
		while (pro && j--) pro = pro->next;
		if (pro){
			ListNode* cur = newHead->next;
			tp = pro->next;
			while (cur != pro){
				newHead->next = cur->next;
				cur->next = pro->next;
				pro->next = cur;
				cur = newHead->next;
			}
		}
		else
			break;
		newHead = tp;
	}
	return root.next;
}
/*
	µÝ¹é·¨£º
*/
ListNode* reverseKGroup2(ListNode* head, int k) {
	int j = k;
	ListNode* cur = head;
	while (j-- && cur){
		cur = cur->next;
	}
	if (j > -1)
		return head;
	j = k;
	ListNode* pre = reverseKGroup2(cur, k);
	while (j--){
		ListNode* tp = head;
		head = head->next;
		tp->next = pre;
		pre = tp;
	}
	return pre;

}
//int main(){
//	ListNode a1(1), a2(2),a3(3),a4(4);
//	a1.next = &a2;
//	a2.next = &a3;
//	a3.next = &a4;
//	ListNode* res = reverseKGroup2(&a1, 2);
//	return 0;
//}