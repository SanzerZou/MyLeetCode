#include "mainheader.h"
/*
	�ҵķ������Ӷȹ��ߣ�����ʵ�ֵ�Ŀ��
*/
void reorderList(ListNode* head) {
	if (!head || !head->next)
		return;

	ListNode* cur = head;
	ListNode* pro = head;
	while(pro->next->next) pro = pro->next;
	while (cur != pro && cur->next){
		// �����ڵ�
		pro->next->next = cur->next;
		cur->next = pro->next;
		pro->next = NULL;
		// �ƶ��ڵ�
		for (pro = cur; pro->next->next; pro = pro->next);
		cur = cur->next->next;		
	}
}
/*
	��������������Ϊ���룬��һ����з�ת��Ȼ�󽫺�һ�����ǰһ��
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