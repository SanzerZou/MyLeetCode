#include "mainheader.h"
#include <unordered_set>
/*
	方法一：使用一个指针set来存放已经结点，如果遇到保存过的节点则跳出循环
*/
bool hasCycle(ListNode *head) {
	unordered_set<ListNode*> mset;
	while (head){
		if (mset.find(head) != mset.end()){
			return true;
		}
		else{
			mset.insert(head);
		}
		head = head->next;
	}
	return false;
}
/*
	巧妙方法：用两个指针，一个快，一个慢，如果存在环，则快指针一定会与慢指针相遇
	证明：快指针会先进入环，当慢指针进入环时，每一步快指针都会赶上一步，所以最终会相遇
*/
bool hasCycle2(ListNode *head){
	ListNode* a = head;
	ListNode* b = head;
	while (a && b && b->next){
		if (a == b)
			return true;
		else{
			a = a->next;
			b = b->next->next;
		}
	}
	return false;
}