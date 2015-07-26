#include "mainheader.h"
/*
	我的方法复杂度过高，倒是实现的目的
*/
void reorderList(ListNode* head) {
	if (!head || !head->next)
		return;

	ListNode* cur = head;
	ListNode* pro = head;
	while(pro->next->next) pro = pro->next;
	while (cur != pro && cur->next){
		// 交换节点
		pro->next->next = cur->next;
		cur->next = pro->next;
		pro->next = NULL;
		// 移动节点
		for (pro = cur; pro->next->next; pro = pro->next);
		cur = cur->next->next;		
	}
}
/*
	方法二：将链拆为两半，后一半进行反转，然后将后一半插入前一半
*/
ListNode* reverse(ListNode* head){
	if (!head || !head->next)
		return head;

	ListNode* cur = NULL;
	while (head){
		ListNode* tp = head;
		head = head->next;
		tp->next = cur;
		cur = tp;
	}
	return cur;
}
void reorderList2(ListNode* head){
	if (!head || !head->next)
		return;

	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* reverseHead = slow->next;
	slow->next = NULL;
	reverseHead = reverse(reverseHead);

	ListNode root(0);
	ListNode* cur = &root;
	while (head && reverseHead){
		cur->next = head;
		head = head->next;
		cur = cur->next;
		cur->next = reverseHead;
		reverseHead = reverseHead->next;
		cur = cur->next;
	}

}
//int main(){
//	ListNode one(1);
//	ListNode two(2);
//	ListNode three(3);
//	one.next = &two;
//	two.next = &three;
//	ListNode* res = reverse(&one);
//	return 0;
//}